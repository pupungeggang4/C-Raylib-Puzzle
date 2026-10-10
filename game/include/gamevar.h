#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"
#include "board.h"

typedef struct GameVar {
    int running;
    int width, height;
    Camera2D camera;
    Board board;
} GameVar;

extern GameVar gameVar;

#endif
