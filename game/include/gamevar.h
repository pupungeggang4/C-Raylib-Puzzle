#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"
#include "entity.h"
#include "board.h"

typedef struct GameVar {
    int running;
    float delta;

    int scene;
    int state;
    int menu;

    int selectedTitle;
    int selectedMenu;

    Board board;
} GameVar;

extern GameVar gameVar;

#endif
