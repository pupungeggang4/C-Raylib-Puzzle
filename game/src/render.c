#include "render.h"

void renderDrawRect(float rect[4], Color color) {
    DrawRectangle(rect[0], rect[1], rect[2], rect[3], color);
}

void renderDrawText(const char* text, float pos[2], int size, Color color) {
    DrawText(text, pos[0], pos[1], size, color);
}

void renderDrawTexture(Texture2D texture, float pos[4]) {
    DrawTexture(texture, pos[0], pos[1], WHITE);
}
