#include "game.h"
#include "scene.h"
#include "util.h"
#include "asset.h"

void gameInit(GameVar* gameVar) {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Puzzle Game");
    #else
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, "Puzzle Game");
    #if !defined(__APPLE__)
    Vector2 dpiScale = GetWindowScaleDPI();
    gameVar->width = (int)(800 * dpiScale.x);
    gameVar->height = (int)(600 * dpiScale.y);
    SetWindowSize(gameVar->width, gameVar->height);
    #endif
    #endif
    SetExitKey(KEY_NULL);

    loadFile(gameVar);
    assetLoad(&asset);

    gameVar->running = 1;
    gameVar->scene = TITLE;
    gameVar->state = NORMAL;

    Entity tempPlayer = {0};
    gameVar->player = tempPlayer;
}

void gameLoop(GameVar* gameVar) {
    gameVar->delta = GetFrameTime();
    gameInputHandle(gameVar);

    if (gameVar->scene == TITLE) {
        sceneTitleUpdate(gameVar);
    } else if (gameVar->scene == FIELD) {
        sceneFieldUpdate(gameVar);
    }
    
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (gameVar->scene == TITLE) {
        sceneTitleRender(gameVar);
    } else if (gameVar->scene == FIELD) {
        sceneFieldRender(gameVar);
    }
    EndDrawing();

    // Terminate part
    #ifdef __EMSCRIPTEN__
    if (gameVar->running == 0) {
        emscripten_cancel_main_loop();
    }
    #else
    if (WindowShouldClose()) {
        gameVar->running = 0;
    }
    #endif
}

void gameInputHandle(GameVar* gameVar) {    
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetMousePosition();
        printf("(%.0f, %.0f)\n", pos.x, pos.y);

        if (gameVar->scene == TITLE) {
            sceneTitleMouseUp(gameVar, pos);
        } else if (gameVar->scene == FIELD) {
            sceneFieldMouseUp(gameVar, pos);
        }
    }

    if (gameVar->scene == TITLE) {
        sceneTitleKeyHandle(gameVar);
    } else if (gameVar->scene == FIELD) {
        sceneFieldKeyHandle(gameVar);
    }
}
