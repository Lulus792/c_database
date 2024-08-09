#include "menubar.h"
#include "main_window.h"
#include <string>

#define MENU_FILE		"File"
#define MENU_EDIT		"Edit"
#define MENU_VIEW		"View"
#define MENU_SETTINGS	"Settings"
#define MENU_HELP		"Help"

static void set_menu(int menu_num, Color color, char *title, Rectangle rect) {
	window_ui.menubar[menu_num].color = color;
	window_ui.menubar[menu_num].title = title;
	window_ui.menubar[menu_num].rect = rect;
}

void set_menubar_ui(void) {
	set_menu(&window_ui.menubar[0], GRAY, MENU_FILE, (Rectangle) { 0, 0, MENU_WIDTH(strlen(MENU_FILE)), MENU_HEIGHT });
	set_menu(&window_ui.menubar[1], GRAY, MENU_EDIT, (Rectangle) { 0, 0, MENU_WIDTH(strlen(MENU_EDIT)), MENU_HEIGHT });
	set_menu(&window_ui.menubar[2], GRAY, MENU_VIEW, (Rectangle) { 0, 0, MENU_WIDTH(strlen(MENU_VIEW)), MENU_HEIGHT });
	set_menu(&window_ui.menubar[3], GRAY, MENU_SETTINGS, (Rectangle) { 0, 0, MENU_WIDTH(strlen(MENU_SETTINGS)), MENU_HEIGHT });
	set_menu(&window_ui.menubar[4], GRAY, MENU_HELP, (Rectangle) { 0, 0, MENU_WIDTH(strlen(MENU_HELP)), MENU_HEIGHT });
}

void draw_menubar_ui(void) {
	for (unsigned int i = 0; i < MENU_COUNT; i++) {
		DrawRectangleRec(window_ui.menubar[i].rect, window_ui.menubar[i].color);
	}
}