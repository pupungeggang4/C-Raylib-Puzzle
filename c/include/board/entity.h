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
    int facing;
    int state;

    // Position
    Vector2 position;
    Vector2i cellPos;
    Vector2i destination;

    // Rendering
    int texCoordIndex[2];
    int frame;
    float frameTime;

    // Animation, Physics
    int moving;
    int movingDirection;
    float movedDistance;
} Entity;

extern float tableDrawEntity[100][4];
extern float tableDrawPlayer[16][4];

#endif
