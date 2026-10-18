#include "asset.h"

Asset asset = {0};

void assetLoad(Asset* asset) {
    asset->buttonMenu = LoadTexture("asset/button_menu.png");
    asset->arrow = LoadTexture("asset/arrow.png");
}

void assetDispose(Asset* asset) {
    UnloadTexture(asset->buttonMenu);
    UnloadTexture(asset->arrow);
}
