#ifndef SCENE_H
#define SCENE_H

#include "includes.h"

typedef struct GameVar GameVar;

void sceneChangeTo(GameVar*, int);

void sceneTitleReady(GameVar*);
void sceneTitleUpdate(GameVar*);
void sceneTitleRender(GameVar*);
void sceneTitleKeyHandle(GameVar*);
void sceneTitleMouseUp(GameVar*, Vector2);

void sceneFieldReady(GameVar*);
void sceneFieldUpdate(GameVar*);
void sceneFieldRender(GameVar*);
void sceneFieldKeyHandle(GameVar*);
void sceneFieldMouseUp(GameVar*, Vector2);

#endif
