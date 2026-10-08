#ifndef ENTITY_H
#define ENTITY_H

#include "includes.h"
#include "shape.h"

typedef struct Entity {
    int type;
    int movable;
    int solid;
    Vector2i cellPos;
} Entity;

#endif
