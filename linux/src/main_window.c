#include "main_window.h"
#include <raylib.h>

window_properys window_prop;

void init_main_window(void) {
  window_prop.w_scale = 0.8f; window_prop.h_scale = 0.8f;
  window_prop.display = GetCurrentMonitor(); 
  window_prop.width = GetMonitorWidth(window_prop.display);
  window_prop.height = GetMonitorHeight(window_prop.display);

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(window_prop.height, window_prop.height, TITLE);
  SetTargetFPS(TARGET_FPS);
}

void run_main_window(void) {
  while(!WindowShouldClose()) {
    BeginDrawing(); {

    } EndDrawing();
  }
  CloseWindow();
}
