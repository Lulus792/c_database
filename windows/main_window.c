#include "main_window.h"
#include "event_handler.h"

window_propertys propertys = { .w_scale = 0.8f, .h_scale = 0.8f };
window_attributes window_ui = { 0 };

static void set_window_propertys(void) {
    propertys.max_width = GetMonitorWidth(0);
    propertys.max_height = GetMonitorHeight(0);
    propertys.width = (int)(propertys.w_scale * propertys.max_width);
    propertys.height = (int)(propertys.h_scale * propertys.max_height);
    propertys.position = GetWindowPosition();
    SetWindowSize(propertys.width, propertys.height);
    SetWindowPosition((propertys.max_width / 2) - (propertys.width / 2),
        (propertys.max_height / 2) - (propertys.height / 2));
}

void init_main_window(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(propertys.width, propertys.height, TITLE);
    //SetWindowState(FLAG_WINDOW_UNDECORATED);
    SetTargetFPS(TARGET_FPS);

    set_window_propertys();
    set_menubar_ui();
}

void run_main_window(void) {

    while (!WindowShouldClose()) {

        if (IsWindowResized()) {
            resize_event();
        }

        BeginDrawing(); {

            draw_menubar_ui();

        } EndDrawing();
    }
    CloseWindow();
}
