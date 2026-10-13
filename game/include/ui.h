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

typedef struct UIField {
    float buttonMenu[4];
} UIField;

typedef struct UIMenu {
    float rect[4];
    float textPaused[2];
    float buttonResume[4];
    float textResume[2];
    float buttonRestart[4];
    float textRestart[2];
    float buttonExit[4];
    float textExit[2];
    float buttonQuit[4];
    float textQuit[2];
    float arrow[6];
} UIMenu;

extern UITitle uiTitle;
extern UIField uiField;
extern UIMenu uiMenu;

#endif
