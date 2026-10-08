#include "includes.h"
#include "gamevar.h"
#include "game.h"

int main(int argc, char** argv) {
    gameInit(&gameVar);
    while (gameVar.running) {
        gameLoop(&gameVar);
    }
    CloseWindow();
    return 0;
}
