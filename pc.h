
#ifndef __pc_h__
#define __pc_h__
typedef struct {
    char use[32];
    int processors;
    char type_proc[16];
    int memory;
    int type_video;
    int volume_video;
    int type_win;
    int winchesters;
    int vol_win;
    int controllers;
    int devises;
    char system[16];
} pc;
#endif