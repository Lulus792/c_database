#ifndef _MENUBAR_
#define _MENUBAR_

#include <raylib.h>

#define MENU_COUNT 5
#define MENU_WIDTH(x) (float)(x + 5)
#define MENU_HEIGHT 10.0f

typedef struct {
	Color color;
	char *description;
} action_t;

typedef struct {
	Color color;
	Rectangle rect;
	char *title;
	action_t *sub_menus;
} menu_t;

void set_menubar_ui(void);

void draw_menubar_ui(void);

#endif