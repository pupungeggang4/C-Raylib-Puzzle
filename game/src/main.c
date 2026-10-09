#include "includes.h"
#include "gamevar.h"
#include "game.h"

#ifdef __EMSCRIPTEN__
void emLoop() {
    gameLoop(&gameVar);
}

EMSCRIPTEN_KEEPALIVE
void emRun() {
    gameInit(&gameVar);
    emscripten_set_main_loop(emLoop, 0, 0);
}
#endif

int main(int argc, char** argv) {
    #ifdef __EMSCRIPTEN__
    EM_ASM({
        try { FS.mkdir('/save'); } catch(e) {}
        FS.mount(FS.filesystems.IDBFS, {}, '/save');
        Module.print("IDBFS 마운트 완료");
        FS.syncfs(true, function(err) {
            if (err) Module.print(err);
            else Module.print("Load complete!");
            _emRun();
        });
    });
    #else
    gameInit(&gameVar);
    while (gameVar.running) {
        gameLoop(&gameVar);
    }
    CloseWindow();
    return 0;
    #endif
}
