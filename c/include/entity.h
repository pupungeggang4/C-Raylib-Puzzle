#ifndef ENTITY_H
#define ENTITY_H

#include "includes.h"
#include "shape.h"

typedef struct Entity {
    // Identity, state
    int valid;
    int type;
    int texture;
    int frame;
    float frameTime;

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

extern float entityDrawCoord[100][4];
extern float playerDrawCoord[16][4];
extern int textureMap[100];

#endif
