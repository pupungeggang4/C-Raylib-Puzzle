#include "board/entityhandler.h"
#include "render.h"
#include "asset.h"

void wallInit(Entity* entity, int state) {
    entity->texCoordIndex[0] = T_WALL;
    entity->texCoordIndex[1] = T_WALL;
    entity->solid = TRUE;
    entity->movable = FALSE;
}

void rockInit(Entity* entity, int state) {
    entity->texCoordIndex[0] = T_ROCK;
    entity->texCoordIndex[1] = T_ROCK;
    entity->solid = TRUE;
    entity->movable = TRUE;
}

void waterInit(Entity* entity, int state) {
    entity->texCoordIndex[0] = T_WATER;
    entity->texCoordIndex[1] = T_WATER;
    entity->solid = TRUE;
    entity->movable = TRUE;
}

void gateInit(Entity* entity, int state) {
    entity->texCoordIndex[0] = T_GATE_OFF;
    entity->texCoordIndex[1] = T_GATE_ON;
    entity->solid = TRUE;
    entity->movable = FALSE;
}

void goalInit(Entity* entity, int state) {
    entity->texCoordIndex[0] = T_GOAL;
    entity->texCoordIndex[1] = T_GOAL;
    entity->solid = FALSE;
    entity->movable = FALSE;
}
