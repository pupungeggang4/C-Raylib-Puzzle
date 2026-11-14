#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"
#include "board/entity.h"
#include "board/board.h"

typedef struct GameVar {
    int running;
    float delta;
    Camera2D camera;

    int scene;
    int state;
    int menu;

    int selectedTitle;
    int selectedMenu;

    Board board;
} GameVar;

extern GameVar gameVar;

#endif
