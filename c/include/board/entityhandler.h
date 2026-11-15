#ifndef ENTITYHANDLER_H
#define ENTITYHANDLER_H

#include "includes.h"
#include "entity.h"

void entityInit(Entity*, int, int, int, int);
void entityHandleInput(Entity*);
void entityMove(Entity*, int);
void entityFollow(Entity*, Camera2D*);
void entityUpdate(Entity*, float);
void entityRender(Entity*, float);

void playerInit(Entity*);
void playerRender(Entity*);
void wallInit(Entity*, int);
void wallRender(Entity*);
void rockInit(Entity*, int);
void rockRender(Entity*);

#endif
