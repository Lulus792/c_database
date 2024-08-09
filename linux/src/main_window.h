#ifndef _MAINWINDOW_
#define _MAINWINDOW_

#include <raylib.h>
#include "settings.h"
#include "menubar.h"

typedef struct {
	menu_t menubar[MENU_COUNT];
} window_attributes;

extern window_attributes window_ui;

void init_main_window(void);

void run_main_window(void);

#endif
