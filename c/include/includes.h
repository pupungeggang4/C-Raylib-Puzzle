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
enum Bool {FALSE, TRUE};
enum Diection {LEFT, RIGHT, UP, DOWN};
enum EntityType {EMPTY, PLAYER, WALL, WATER, FLOWER, ROCK, LOCK, GATE, GOAL};
enum EntityTexture {
    T_EMPTY, T_WALL, T_WATER, T_FLOWER_OFF, T_FLOWER_ON, T_ROCK, T_LOCK_OFF, T_LOCK_ON, T_GATE_OFF, T_GATE_ON,
    T_GOAL
};

typedef struct Board Board;

#endif
