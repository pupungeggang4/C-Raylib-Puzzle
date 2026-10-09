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
