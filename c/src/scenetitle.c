#include "scene.h"
#include "game.h"
#include "gamevar.h"
#include "ui.h"
#include "util.h"
#include "render.h"
#include "asset.h"

void sceneTitleReady(GameVar* gameVar) {
    gameVar->selectedTitle = 0;
}

void sceneTitleUpdate(GameVar* gameVar) {
}

void sceneTitleRender(GameVar* gameVar) {
    renderDrawText("Puzzle", uiTitle.textTitle, 20, BLACK);
    renderDrawRect(uiTitle.buttonStart, YELLOW);
    renderDrawText("Start Game", uiTitle.textStart, 20, BLACK);
    renderDrawRect(uiTitle.buttonErase, PINK);
    renderDrawText("Erase Data", uiTitle.textErase, 20, BLACK);
    renderDrawRect(uiTitle.buttonQuit, YELLOW);
    renderDrawText("Quit Game", uiTitle.textQuit, 20, BLACK);

    float arrow[4] = {
        uiTitle.arrow[0], uiTitle.arrow[1] + uiTitle.arrow[3] * gameVar->selectedTitle,
        uiTitle.arrow[4], uiTitle.arrow[5]
    };
    renderDrawTexture(asset.arrow, arrow);
}

void sceneTitleKeyHandle(GameVar* gameVar) {
    if (IsKeyPressed(KEY_DOWN)) {
        gameVar->selectedTitle = (gameVar->selectedTitle + 1) % 3;
    } else if (IsKeyPressed(KEY_UP)) {
        gameVar->selectedTitle = (gameVar->selectedTitle + 2) % 3;
    } else if (IsKeyPressed(KEY_ENTER)) {
        if (gameVar->selectedTitle == 0) {
            sceneChangeTo(gameVar, FIELD);
        } else if (gameVar->selectedTitle == 1) {
        } else if (gameVar->selectedTitle == 2) {
            gameVar->running = false;
        }
    }
}

void sceneTitleMouseUp(GameVar* gameVar, Vector2 pos) {
    if (pointInsideRectUI(pos, uiTitle.buttonStart)) sceneChangeTo(gameVar, FIELD);
    if (pointInsideRectUI(pos, uiTitle.buttonQuit)) gameVar->running = false;
}
