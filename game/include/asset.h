#ifndef ASSET_H
#define ASSET_H

#include "includes.h"

typedef struct Asset {
    Texture2D buttonMenu;
    Texture2D arrow;
    Texture2D entity;
    Texture2D player;
} Asset;

extern Asset asset;

void assetLoad(Asset*);
void assetDispose(Asset*);

#endif
