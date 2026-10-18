#ifndef GAMEVAR_H
#define GAMEVAR_H

#include "includes.h"
#include "entity.h"
#include "board.h"

typedef struct GameVar {
    int running;
    int width, height;
    float scale;
    float delta;

    int scene;
    int state;
    int menu;

    int selectedTitle;
    int selectedMenu;

    Board board;
    Entity player;
} GameVar;

extern GameVar gameVar;

#endif
