#include "board/entityhandler.h"
#include "board/board.h"
#include "render.h"
#include "asset.h"

void entityInit(Entity* entity, int type, int x, int y, int state) {
    // General
    entity->valid = 1;
    entity->type = type;
    entity->frameTime = 0;
    entity->state = 0;
    entity->facing = DOWN;

    entity->cellPos.x = x; entity->cellPos.y = y;
    entity->destination.x = x; entity->destination.y = y;
    entity->position.x = x * 40; entity->position.y = y * 40;

    entity->moving = 0;
    entity->movedDistance = 0;
    entity->movingDirection = DOWN;

    // Add solid movable, texcoord
    switch (type) {
        case WALL: wallInit(entity, state); break;
        case ROCK: rockInit(entity, state); break;
        case WATER: waterInit(entity, state); break;
        case GATE: gateInit(entity, state); break;
        case GOAL: goalInit(entity, state); break;
        default: break;
    }
}

void entityHandleInput(Entity* entity, Board* board) {
    if (IsKeyPressed(KEY_LEFT)) {
        entityMove(entity, board, LEFT);
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        entityMove(entity, board, RIGHT);
    }
    if (IsKeyPressed(KEY_UP)) {
        entityMove(entity, board, UP);
    }
    if (IsKeyPressed(KEY_DOWN)) {
        entityMove(entity, board, DOWN);
    }
}

void entityMove(Entity* entity, Board* board, int direction) {
    if (entity->moving == 0) {
        entity->facing = direction;

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

        if (entityMoveCheck(entity, board)) {
            entity->moving = 1;
            entity->movedDistance = 0;
            entity->movingDirection = direction;
            entity->cellPos.x = entity->destination.x;
            entity->cellPos.y = entity->destination.y;
        }
    }
}

int entityMoveCheck(Entity* entity, Board* board) {
    for (int i = 0; i < 256; i++) {
        Entity* target = &board->entityList[i];
        if (target->valid) {
            if (vector2iEqual(target->cellPos, entity->destination)) {
                if (target->solid && !target->movable) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

void entityFollow(Entity* entity, Camera2D* camera) {
}

void entityUpdate(Entity* entity, float delta) {
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

void entityRender(Entity* entity, float delta) {
    entity->frameTime += delta;

    if (entity->type != PLAYER) {
        int texIndex = entity->texCoordIndex[entity->state];
        Rectangle rect = {
            tableDrawEntity[texIndex][0], tableDrawEntity[texIndex][1],
            tableDrawEntity[texIndex][2], tableDrawEntity[texIndex][3]
        };
        Rectangle dest = {entity->position.x, entity->position.y, 40, 40};
        Vector2 origin = {0, 0};
        DrawTexturePro(asset.entity, rect, dest, origin, 0, WHITE);
    } else {
        int frame = 0;
        if (entity->moving) frame += 8;
        frame += entity->facing * 2;
        frame += (int)(entity->frameTime / 0.4) % 2;
        Rectangle rect = {
            tableDrawPlayer[frame][0], tableDrawPlayer[frame][1],
            tableDrawPlayer[frame][2], tableDrawPlayer[frame][3]
        };
        Rectangle dest = {entity->position.x, entity->position.y, 40, 40};
        Vector2 origin = {0, 0};
        DrawTexturePro(asset.player, rect, dest, origin, 0, WHITE);
    }
}
