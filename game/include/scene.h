#ifndef SCENE_H
#define SCENE_H

#include "includes.h"

typedef struct GameVar GameVar;

void sceneTitleUpdate(GameVar*);
void sceneTitleRender(GameVar*);
void sceneTitleKeyDown(GameVar*);
void sceneTitleMouseUp(GameVar*);

#endif
