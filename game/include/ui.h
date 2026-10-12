#ifndef UI_H
#define UI_H

typedef struct UITitle {
    float textTitle[2];
    float buttonStart[4];
    float textStart[2];
    float buttonErase[4];
    float textErase[2];
    float buttonQuit[4];
    float textQuit[2];
    float arrow[6];
} UITitle;

extern UITitle uiTitle;

#endif
