#include "board/entityhandler.h"
#include "render.h"
#include "asset.h"

void rockInit(Entity* entity, int state) {
    entity->texCoordIndex[0] = T_WALL;
    entity->texCoordIndex[1] = T_WALL;
}

void rockRender(Entity* entity) {

}
