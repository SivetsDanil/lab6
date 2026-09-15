#include <stdio.h>
#include "pc.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    char fname[64];
    snprintf(fname, sizeof(fname), "test%s.txt", argv[3]);
    FILE *file = fopen(fname, "r");
    if (!file) { fprintf(stderr, "wrong test\n");
        return 2;
    }
    FILE *out = fopen(argv[1], "wb");
    if (!out) {
        fprintf(stderr, "Error opening\n");
        fclose(file);
        return 2;
    }
    pc p;
    int c = 0;
    while (fscanf(file, "%31s %d %15s %d %d %d %d %d %d %d %d %15s",
                 p.use,
                 &p.processors,
                 p.type_proc,
                 &p.memory,
                 &p.type_video,
                 &p.volume_video,
                 &p.type_win,
                 &p.winchesters,
                 &p.vol_win,
                 &p.controllers,
                 &p.devises,
                 p.system) == 12) {
        fwrite(&p, sizeof(pc), 1, out);
        c++;
    }
    fclose(file);
    fclose(out);
    printf("Successfully written %d records from %s to %s\n", c, fname, argv[1]);
    return 0;
}