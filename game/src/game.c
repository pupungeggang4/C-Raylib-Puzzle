#include "game.h"

void gameInit(GameVar* gameVar) {
    #ifdef __EMSCRIPTEN__
    InitWindow(800, 600, "Puzzle Game");
    #else
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Puzzle Game");
    #ifndef __APPLE__
    Vector2 dpiScale = GetWindowScaleDPI();
    int width = (int)(800 * dpiScale.x);
    int height = (int)(600 * dpiScale.y);
    SetWindowSize(width, height);
    #endif
    SetTargetFPS(60);
    #endif

    gameVar->running = 1;
}

void gameLoop(GameVar* gameVar) {
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
