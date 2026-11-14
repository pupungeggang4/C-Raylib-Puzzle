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
    #ifdef __EMSCRIPTEN__
    char* path = "/save/save.txt";
    #else
    char* path = "save/save.txt";
    #endif

    FILE *fp = fopen(path, "r");
    if (!fp) {
        FILE *temp = fopen(path, "w");
        fprintf(temp, "1 2 3 4\n");
        fclose(temp);
        fp = fopen(path, "r");
    }

    fclose(fp);
}

void saveFile(GameVar* gameVar) {
    #ifdef __EMSCRIPTEN__
    char* path = "/save/save.txt";
    #else
    char* path = "save/save.txt";
    #endif

    FILE *fp = fopen(path, "w");
    fclose(fp);

    #ifdef __EMSCRIPTEN__
    syncDB();
    #endif
}

void readFile(const char* path) {
    FILE *fp = fopen(path, "r");
    if (!fp) {
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s\n", buffer);
    }
    fclose(fp);
}

int pointInsideRectUI(Vector2 pos, float rect[4]) {
    return pos.x > rect[0] && pos.x < rect[0] + rect[2] && pos.y > rect[1] && pos.y < rect[1] + rect[3];
}
