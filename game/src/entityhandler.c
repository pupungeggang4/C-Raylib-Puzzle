#include "entityhandler.h"
#include "render.h"
#include "asset.h"

void entityInit(Entity* entity, int type, int x, int y) {
    entity->valid = 1;
    entity->type = type;
    // Add solid movable
    entity->state = 0;
    entity->facing = DOWN;

    entity->cellPos.x = x; entity->cellPos.y = y;
    entity->destination.x = x; entity->destination.y = y;
    entity->position.x = x * 40; entity->position.y = y * 40;

    entity->moving = 0;
    entity->movedDistance = 0;
    entity->movingDirection = DOWN;
}

void entityHandleInput(Entity* entity) {
    if (IsKeyPressed(KEY_LEFT)) {
        entityMove(entity, LEFT);
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        entityMove(entity, RIGHT);
    }
    if (IsKeyPressed(KEY_UP)) {
        entityMove(entity, UP);
    }
    if (IsKeyPressed(KEY_DOWN)) {
        entityMove(entity, DOWN);
    }
}

void entityMove(Entity* entity, int direction) {
    if (entity->moving == 0) {
        entity->moving = 1;
        entity->movedDistance = 0;
        entity->movingDirection = direction;

        if (direction == LEFT) {
            entity->destination.x = entity->cellPos.x - 1;
            entity->destination.y = entity->cellPos.y;
        } else if (direction == RIGHT) {
            entity->destination.x = entity->cellPos.x + 1;
            entity->destination.y = entity->cellPos.y;
        } else if (direction == UP) {
            entity->destination.x = entity->cellPos.x;
            entity->destination.y = entity->cellPos.y - 1;
        } else if (direction == DOWN) {
            entity->destination.x = entity->cellPos.x;
            entity->destination.y = entity->cellPos.y + 1;
        }
        entity->cellPos.x = entity->destination.x;
        entity->cellPos.y = entity->destination.y;
    }
}

void entityFollow(Entity* entity, Camera2D* camera) {
}

void entityHandleTick(Entity* entity, float delta) {
    if (entity->moving == 1) {
        if (entity->movingDirection == LEFT) {
            entity->position.x -= 200.0f * delta;
        } else if (entity->movingDirection == RIGHT) {
            entity->position.x += 200.0f * delta;
        } else if (entity->movingDirection == UP) {
            entity->position.y -= 200.0f * delta;
        } else if (entity->movingDirection == DOWN) {
            entity->position.y += 200.0f * delta;
        }

        entity->movedDistance += 200.0f * delta;

        if (entity->movedDistance >= 40) {
            entity->moving = 0;
            entity->position.x = entity->destination.x * 40.0f;
            entity->position.y = entity->destination.y * 40.0f;
        }
    }
}

void entityRender(Entity* entity) {
    if (entity->type > 0) {
        Rectangle rect = {entityDrawCoord[entity->type][0], entityDrawCoord[entity->type][1], entityDrawCoord[entity->type][2], entityDrawCoord[entity->type][3]};
        Rectangle dest = {entity->position.x, entity->position.y, 40, 40};
        Vector2 origin = {0, 0};
        DrawTexturePro(asset.entity, rect, dest, origin, 0, WHITE);
    } else {
        DrawRectangle(entity->position.x, entity->position.y, 40.0f, 40.0f, BLUE);
    }
}
