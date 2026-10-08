#ifndef BOARD_H
#define BOARD_H

#include "entity.h"

typedef struct Board {
    int row;
    int col;
    Entity entityList[256]; 
} Board;

#endif
