#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H

#include "includes.h"
#include "entity.h"

void entityInit(Entity*, int, int, int, int);
void entityHandleInput(Entity*, Board*);
void entityMove(Entity*, Board*, int);
int entityMoveCheck(Entity*, Board*);
void entityFollow(Entity*, Camera2D*);
void entityUpdate(Entity*, float);
void entityRender(Entity*, float);

void playerInit(Entity*);
void wallInit(Entity*, int);
void rockInit(Entity*, int);
void waterInit(Entity*, int);
void gateInit(Entity*, int);
void goalInit(Entity*, int);

#endif
