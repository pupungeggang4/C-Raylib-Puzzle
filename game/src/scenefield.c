#include "scene.h"
#include "game.h"
#include "gamevar.h"
#include "ui.h"
#include "util.h"
#include "render.h"

void sceneFieldReady(GameVar* gameVar) {
    gameVar->menu = 0;
}

void sceneFieldUpdate(GameVar* gameVar) {
}

void sceneFieldRender(GameVar* gameVar) {
    renderDrawText("Test", uiTitle.textTitle, 20, BLACK);
}

void sceneFieldKeyHandle(GameVar* gameVar) {
}

void sceneFieldMouseUp(GameVar* gameVar, Vector2 pos) {
    if (pointInsideRectUI(pos, uiTitle.buttonQuit)) gameVar->running = false;
}
