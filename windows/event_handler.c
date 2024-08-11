#include "event_handler.h"

void resize_event() {
	propertys.width = GetScreenWidth();
	propertys.height = GetScreenHeight();
	propertys.position = GetWindowPosition();
}