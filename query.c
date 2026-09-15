#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pc.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr,"Wrong input\n");
        return 1;
    }
    FILE *db = fopen(argv[1], "rb");
    if (!db) {
        fprintf(stderr, "Error opening db file\n");
        return 2;
    }
    pc p;
    int n;
    if (argc == 3 && !strcmp(argv[2], "-f")) {
        while (fread(&p, sizeof(pc), 1, db) == 1) {
            printf("%s | CPU: %d | RAM: %d | Dev: %d | OS: %s\n",
                   p.use, p.processors, p.memory, p.devises, p.system);
        }
    } else if (argc == 4 && strcmp(argv[2], "-p") == 0) {
        while (fread(&p, sizeof(pc), 1, db) == 1) {
            n = atoi(argv[3]);
            if (p.devises < n) {
                printf("%-30s devices: %d, min: %d -> lacks %d (OS: %s)\n",p.use, p.devises, n, n - p.devises, p.system);
            }
        }
    }
    fclose(db);
    return 0;
}