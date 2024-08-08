#ifndef _SETTINGS_
#define _SETTINGS_

#define TITLE   "Database"
#define TARGET_FPS 60

typedef struct {
  int width;
  int height;
  float w_scale;
  float h_scale;
  int display;
} window_properys;

extern window_properys window_prop;

#endif
