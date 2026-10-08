#include "game.h"

void gameInit(GameVar* gameVar) {
    InitWindow(800, 600, "Puzzle Game");
    gameVar->running = 1;
}

void gameLoop(GameVar* gameVar) {
    BeginDrawing();
    EndDrawing();
    if (WindowShouldClose()) {
        gameVar->running = 0;
    }
}
