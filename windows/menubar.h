#ifndef _MENUBAR_
#define _MENUBAR_

#include <raylib.h>

#define FONT_SIZE 20 
#define MENU_COUNT 5
#define MENU_HEIGHT 30
#define MENU_MARGIN_MUL 1.5f
#define TEXT_PADDING_X 3
#define TEXT_PADDING_Y 5

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