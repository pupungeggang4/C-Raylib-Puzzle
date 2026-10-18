#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H

#include "includes.h"
#include "entity.h"

void entityHandleInput(Entity*);
void entityMove(Entity*, int);
void entityFollow(Entity*, Camera2D*);
void entityHandleTick(Entity*, float);
void entityRender(Entity*);

#endif
