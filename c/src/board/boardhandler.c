#include "board/entity.h"
#include "board/board.h"
#include "board/entityhandler.h"
#include "board/boardhandler.h"

void boardLoad(Board* board, const char* path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("File Load Failed\n");
        return;
    } else {
        int px = 0, py = 0;
        fscanf(fp, "%d %d", &px, &py);
        entityInit(&board->player, PLAYER, px, py, 0);
        for (int i = 0; i < 256; i++) {
            board->entityList[i].valid = 0;
        } 
        for (int i = 0; i < 256; i++) {
            int type = 0, x = 0, y = 0, state = 0;
            if (fscanf(fp, "%d %d %d %d", &type, &x, &y, &state) == 4) {
                entityInit(&board->entityList[i], type, x, y, state);
            } else break;
        } 
        fclose(fp);
    }
}
