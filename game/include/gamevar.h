#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"
#include "board.h"

typedef struct GameVar {
    int running;
    int width, height;
    Camera2D camera;

    int scene;
    int state;
    Board board;
} GameVar;

extern GameVar gameVar;

#endif
