#include "scene.h"
#include "game.h"
#include "gamevar.h"

#include "ui.h"
#include "util.h"
#include "render.h"
#include "asset.h"
#include "entityhandler.h"

void sceneFieldReady(GameVar* gameVar) {
    gameVar->menu = 0;
    gameVar->selectedMenu = 0;
}

void sceneFieldUpdate(GameVar* gameVar) {
    if (gameVar->menu == 0) {
        if (gameVar->state == NORMAL) {
            entityHandleTick(&gameVar->player, gameVar->delta);
        }
    }
}

void sceneFieldRender(GameVar* gameVar) {
    entityRender(&gameVar->player);
    renderDrawTexture(asset.buttonMenu, uiField.buttonMenu);
    for (int i = 0; i < 256; i++) {
        Entity* entity = &gameVar->board.entityList[i];
        if (entity->valid) {
            entityRender(entity);
        }
    }

    if (gameVar->menu == 1) {
        menuRender(gameVar);
    }
}

void sceneFieldKeyHandle(GameVar* gameVar) {
    if (gameVar->menu == 1) {
        menuKeyHandle(gameVar);
    } else {
        if (gameVar->state == NORMAL) {
            entityHandleInput(&gameVar->player);
        }
        if (IsKeyPressed(KEY_ESCAPE)) {
            gameVar->menu = 1;
            gameVar->selectedMenu = 0;
        }
    }
}

void sceneFieldMouseUp(GameVar* gameVar, Vector2 pos) {
    if (gameVar->menu == 1) {
        if (pointInsideRectUI(pos, uiField.buttonMenu)) {
            gameVar->menu = 0;
        }
        menuMouseUp(gameVar, pos);
    } else {
        if (pointInsideRectUI(pos, uiField.buttonMenu)) {
            gameVar->menu = 1;
        }
    }
}

void menuRender(GameVar* gameVar) {
    renderDrawRect(uiMenu.rect, WHITE);
    renderDrawText("Paused", uiMenu.textPaused, 20, BLACK); 
    renderDrawRect(uiMenu.buttonResume, YELLOW);
    renderDrawText("Resume", uiMenu.textResume, 20, BLACK); 
    renderDrawRect(uiMenu.buttonRestart, PINK);
    renderDrawText("Restart", uiMenu.textRestart, 20, BLACK); 
    renderDrawRect(uiMenu.buttonExit, YELLOW);
    renderDrawText("Exit", uiMenu.textExit, 20, BLACK);
    renderDrawRect(uiMenu.buttonQuit, PINK);
    renderDrawText("Quit", uiMenu.textQuit, 20, BLACK); 

    float arrow[4] = {
        uiMenu.arrow[0], uiMenu.arrow[1] + uiMenu.arrow[3] * gameVar->selectedMenu,
        uiMenu.arrow[4], uiMenu.arrow[5]
    };

    renderDrawTexture(asset.arrow, arrow);
}

void menuKeyHandle(GameVar* gameVar) {
    if (IsKeyPressed(KEY_ESCAPE)) {
        gameVar->menu = 0;
    }

    if (IsKeyPressed(KEY_DOWN)) gameVar->selectedMenu = (gameVar->selectedMenu + 1) % 4;
    else if (IsKeyPressed(KEY_UP)) gameVar->selectedMenu = (gameVar->selectedMenu + 3) % 4;
    else if (IsKeyPressed(KEY_ENTER)) {
        if (gameVar->selectedMenu == 0) {
            gameVar->menu = 0;
        } else if (gameVar->selectedMenu == 1) {
        } else if (gameVar->selectedMenu == 2) {
            sceneChangeTo(gameVar, TITLE);
        } else if (gameVar->selectedMenu == 3) {
            gameVar->running = false;
        }
    }
}

void menuMouseUp(GameVar* gameVar, Vector2 pos) {
    if (pointInsideRectUI(pos, uiMenu.buttonResume)) {
        gameVar->menu = 0;
    } else if (pointInsideRectUI(pos, uiMenu.buttonRestart)) {
    } else if (pointInsideRectUI(pos, uiMenu.buttonExit)) {
        sceneChangeTo(gameVar, TITLE);
    } else if (pointInsideRectUI(pos, uiMenu.buttonQuit)) {
        gameVar->running = false;
    }
}
