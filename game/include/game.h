#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "gamevar.h"

void gameInit(GameVar*);
void gameLoop(GameVar*);
void gameInputHandle(GameVar*);

#endif
