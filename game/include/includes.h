#ifndef INCLUDES_H
#define INCLUDES_H

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include <raylib.h>
#include <raymath.h>

enum Scene {TITLE, FIELD};
enum State {NORMAL, MENU};

#endif
