#include "util.h"

#ifdef __EMSCRIPTEN__
void syncDB() {
    EM_ASM({
        if (window.isSaving) return;
        window.isSaving = true;
        Module.print("Saving... do not close the tab.");

        FS.syncfs(false, function(err) {
            window.isSaving = false;
            if (err) Module.print(err);
            else Module.print("Save complete!");
        });
    });
}
#endif

void loadFile(GameVar* gameVar) {
}

void saveFile(GameVar* gameVar) {
}

int pointInsideRectUI(Vector2 pos, float rect[4]) {
    return pos.x > rect[0] && pos.x < rect[0] + rect[2] && pos.y > rect[1] && pos.y < rect[1] + rect[3];
}