#include "game.h"

void gameInit(GameVar* gameVar) {
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "Puzzle Game");
    #ifndef __APPLE__
    Vector2 dpiScale = GetWindowScaleDPI();
    int width = (int)(800 * dpiScale.x);
    int height = (int)(600 * dpiScale.y);
    SetWindowSize(width, height);
    #endif
    SetTargetFPS(60);
    gameVar->running = 1;
}

void gameLoop(GameVar* gameVar) {
    BeginDrawing();
    EndDrawing();
    if (WindowShouldClose()) {
        gameVar->running = 0;
    }
}
