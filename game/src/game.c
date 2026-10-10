#include "game.h"

void gameInit(GameVar* gameVar) {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Puzzle Game");
    #else
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Puzzle Game");
    #ifndef __APPLE__
    Vector2 dpiScale = GetWindowScaleDPI();
    gameVar->width = (int)(800 * dpiScale.x);
    gameVar->height = (int)(600 * dpiScale.y);
    SetWindowSize(gameVar->width, gameVar->height);
    #endif
    SetTargetFPS(60);
    #endif
    SetExitKey(KEY_NULL);
    
    Camera2D tempCamera = {0};
    gameVar->camera = tempCamera;
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;
    gameVar->running = 1;
}

void gameLoop(GameVar* gameVar) {
    gameVar->camera.zoom = GetRenderWidth() / 800.0f;

    gameInputHandle(gameVar);

    BeginDrawing();
    ClearBackground(RAYWHITE);
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
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        #ifdef __EMSCRIPTEN__
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), gameVar->camera);
        #else
        Vector2 pos = GetScreenToWorld2D(Vector2Scale(GetMousePosition(), GetWindowScaleDPI().x), gameVar->camera);
        #endif
        printf("(%.0f, %.0f)\n", pos.x, pos.y);
    }
}
