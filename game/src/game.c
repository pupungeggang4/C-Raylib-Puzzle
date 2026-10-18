#include "game.h"
#include "scene.h"
#include "util.h"
#include "asset.h"

void gameInit(GameVar* gameVar) {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Puzzle Game");
    #else
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Puzzle Game");
    #if !defined(__APPLE__) && !defined(__ANDROID__)
    printf("1234\n");
    Vector2 dpiScale = GetWindowScaleDPI();
    gameVar->width = (int)(800 * dpiScale.x);
    gameVar->height = (int)(600 * dpiScale.y);
    SetWindowSize(gameVar->width, gameVar->height);
    #endif
    SetTargetFPS(60);
    #endif
    SetExitKey(KEY_NULL);
    Camera2D tempCamera1 = {0}, tempCamera2 = {0};
    gameVar->camera = tempCamera1;
    gameVar->cameraUI = tempCamera2;

    loadFile(gameVar);
    assetLoad(&asset);

    gameVar->camera.zoom = GetRenderWidth() / 800.0f;
    gameVar->cameraUI.zoom = GetRenderWidth() / 800.0f;
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
        #ifdef __EMSCRIPTEN__
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), gameVar->cameraUI);
        #else
        Vector2 pos = GetScreenToWorld2D(Vector2Scale(GetMousePosition(), GetWindowScaleDPI().x), gameVar->cameraUI);
        #endif
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
