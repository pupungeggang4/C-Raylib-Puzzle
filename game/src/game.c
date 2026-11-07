#include "game.h"
#include "scene.h"
#include "util.h"
#include "asset.h"
#include "entityhandler.h"
#include "board.h"
#include "boardhandler.h"

void gameInit(GameVar* gameVar) {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Puzzle Game");
    #else
    float aspRatio = 0.75;
    SetConfigFlags(FLAG_VSYNC_HINT);
    int width = 800, height = 600;
    InitWindow(width, height, "Puzzle Game");
    int mWidth = GetMonitorWidth(0); int mHeight = GetMonitorHeight(0);
    if (mWidth * aspRatio > height) {
        height = (int)(mHeight * 0.8); width = (int)(height / aspRatio);
    } else {
        width = (int)(mWidth * 0.8); height = (int)(width * aspRatio);
    }
    SetWindowSize(width, height);
    SetWindowPosition((mWidth - width) / 2, (mHeight - height) / 2);
    #endif

    SetExitKey(KEY_NULL);

    loadFile(gameVar);
    assetLoad(&asset);

    Camera2D tempCamera = {0}; gameVar->camera = tempCamera;
    gameVar->running = 1;
    gameVar->scene = TITLE;
    gameVar->state = NORMAL;

    boardLoad(&gameVar->board, "data/level1.txt");
}

void gameLoop(GameVar* gameVar) {
    gameVar->camera.zoom = GetRenderWidth() / 800;
    gameVar->delta = GetFrameTime();
    gameInputHandle(gameVar);

    if (gameVar->scene == TITLE) {
        sceneTitleUpdate(gameVar);
    } else if (gameVar->scene == FIELD) {
        sceneFieldUpdate(gameVar);
    }
    
    BeginDrawing();
    BeginMode2D(gameVar->camera);
    ClearBackground(RAYWHITE);
    if (gameVar->scene == TITLE) {
        sceneTitleRender(gameVar);
    } else if (gameVar->scene == FIELD) {
        sceneFieldRender(gameVar);
    }
    EndMode2D();
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
        pos = Vector2Scale(pos, 1 / gameVar->camera.zoom);
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
