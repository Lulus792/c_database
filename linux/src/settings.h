#ifndef _SETTINGS_
#define _SETTINGS_

#define TITLE		"Database"
#define TARGET_FPS	60

typedef struct {
	int width;
	int height;
	int max_width;
	int max_height;
	float w_scale;
	float h_scale;
	Vector2 position;
} window_propertys;

extern window_propertys propertys;

#endif
