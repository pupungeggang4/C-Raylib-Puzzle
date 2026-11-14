#ifndef BOARD_H
#define BOARD_H

#include "entity.h"

typedef struct Board {
    int x;
    int y;
    Entity player;
    Entity entityList[256]; 
} Board;

#endif
