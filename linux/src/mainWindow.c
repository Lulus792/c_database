#include "mainWindow.h"

void init_main_window(void) {
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(TARGET_FPS);
}

void run_main_window(void) {
    while(!WindowShouldClose()) {
        BeginDrawing(); {

        } EndDrawing();
    }
    CloseWindow();
}
