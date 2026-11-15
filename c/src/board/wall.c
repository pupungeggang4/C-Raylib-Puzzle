#include "board/entityhandler.h"
#include "render.h"
#include "asset.h"

void wallInit(Entity* entity, int state) {
    entity->texCoordIndex[0] = T_WALL;
    entity->texCoordIndex[1] = T_WALL;
}

void wallRender(Entity* entity) {

}
