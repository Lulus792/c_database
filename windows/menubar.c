#include "menubar.h"
#include "main_window.h"
#include <string.h>

#define MENU_FILE		"File"
#define MENU_EDIT		"Edit"
#define MENU_VIEW		"View"
#define MENU_SETTINGS	"Settings"
#define MENU_HELP		"Help"

static float get_x_for_text(const menu_t *pre_menu) {
	return pre_menu->rect.x + pre_menu->rect.width;
}

static void set_menu(menu_t *menu, char *title, Rectangle rect) {
	menu->color = GRAY;
	menu->title = title;
	menu->rect = rect;
}

void set_menubar_ui(void) {
	set_menu(&window_ui.menubar[0], MENU_FILE, (Rectangle) { TEXT_PADDING_X, TEXT_PADDING_Y, 
		MeasureText(MENU_FILE, FONT_SIZE) * MENU_MARGIN_MUL, MENU_HEIGHT });
	set_menu(&window_ui.menubar[1], MENU_EDIT, (Rectangle) { get_x_for_text(&window_ui.menubar[0]) + TEXT_PADDING_X,
		TEXT_PADDING_Y, MeasureText(MENU_EDIT, FONT_SIZE) * MENU_MARGIN_MUL, MENU_HEIGHT });
	set_menu(&window_ui.menubar[2], MENU_VIEW, (Rectangle) { get_x_for_text(&window_ui.menubar[1]) + TEXT_PADDING_X,
		TEXT_PADDING_Y, MeasureText(MENU_VIEW, FONT_SIZE) * MENU_MARGIN_MUL, MENU_HEIGHT });
	set_menu(&window_ui.menubar[3], MENU_SETTINGS, (Rectangle) { get_x_for_text(&window_ui.menubar[2]) + TEXT_PADDING_X,
		TEXT_PADDING_Y, MeasureText(MENU_SETTINGS, FONT_SIZE) * MENU_MARGIN_MUL, MENU_HEIGHT });
	set_menu(&window_ui.menubar[4], MENU_HELP, (Rectangle) { get_x_for_text(&window_ui.menubar[3]) + TEXT_PADDING_X,
		TEXT_PADDING_Y, MeasureText(MENU_HELP, FONT_SIZE) * MENU_MARGIN_MUL, MENU_HEIGHT });
}

void draw_menubar_ui(void) {
	DrawRectangle(0, 0, propertys.width, MENU_HEIGHT, GRAY);
	for (unsigned int i = 0; i < MENU_COUNT; i++) {
		menu_t *menu = &window_ui.menubar[i];
		DrawText(menu->title, (int)(menu->rect.x + 1), (int)(menu->rect.y), FONT_SIZE, WHITE);
	}
}