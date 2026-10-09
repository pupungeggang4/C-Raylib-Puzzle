#ifndef UTIL_H
#define UTIL_H

#include "includes.h"

typedef struct GameVar GameVar;

#ifdef __EMSCRIPTEN__
void syncDB();
#endif
void loadFile(GameVar*);
void saveFile(GameVar*);

#endif
