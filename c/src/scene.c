#include "scene.h"
#include "gamevar.h"

void sceneChangeTo(GameVar* gameVar, int scene) {
    gameVar->scene = scene;
    if (gameVar->scene == TITLE) {
        sceneTitleReady(gameVar);
    } else if (gameVar->scene == FIELD) {
        sceneFieldReady(gameVar);
    }
}
