#ifndef ENTITY_H
#define ENTITY_H

#include "includes.h"
#include "shape.h"

typedef struct Entity {
    // Identity, state
    int valid;
    int type;
    int movable;
    int solid;
    int state;
    int facing;

    // Position
    Vector2 position;
    Vector2i cellPos;
    Vector2i destination;

    // Animation, Physics
    int moving;
    int movingDirection;
    float movedDistance;
} Entity;

extern float entityDrawCoord[10][4];

#endif
