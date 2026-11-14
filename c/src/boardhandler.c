#include "entity.h"
#include "board.h"
#include "entityhandler.h"
#include "boardhandler.h"

void boardLoad(Board* board, const char* path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("File Load Failed\n");
        return;
    } else {
        int px = 0, py = 0;
        fscanf(fp, "%d %d", &px, &py);
        entityInit(&board->player, PLAYER, px, py);
        for (int i = 0; i < 256; i++) {
            board->entityList[i].valid = 0;
        } 
        for (int i = 0; i < 256; i++) {
            int type = 0, x = 0, y = 0;
            if (fscanf(fp, "%d %d %d", &type, &x, &y) == 3) {
                entityInit(&board->entityList[i], type, x, y);
            } else break;
        } 
        fclose(fp);
    }
}
