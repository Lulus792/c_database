#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define NUM_FLAGS                 8

#define CMAKE_BUILD_FLAG_SHORT    "-b"
#define CMAKE_BUILD_FLAG_LONG     "--build"
#define RUN_MAIN_FLAG_SHORT       "-rm"
#define RUN_MAIN_FLAG_LONG        "--run_main"
#define CLEAN_BUILD_FLAG_SHORT    "-cb"
#define CLEAN_BUILD_FLAG_LONG     "--clean_build"
#define ONLY_CLEAN_FLAG_SHORT     "-oc"
#define ONLY_CLEAN_FLAG_LONG      "--only_clean"

#define EXECUTE_FILE              "./compile"
#define MAIN_NAME                 "Database"

typedef struct {
  char *main_path;
  char *build_path;
  char *flags[NUM_FLAGS];
  unsigned int flag_count;
} program_info_t; 

int last_occurence(char *s, char c) {
  int position = -1;
  for (unsigned int i = 0; s[i] != '\0'; i++) {
    if (s[i] == c) {
      position = i;
    }
  }
  return position;
}

char *get_path(char *path) {
  if (strcmp(path, EXECUTE_FILE) == 0) {
    return ".";
  }
  unsigned int size = strlen(path);
  char *full_path = malloc((size - 1));

  if (full_path == NULL) {
    fprintf(stderr, "Malloc failed\n");
    return NULL;
  }

  strncpy(full_path, path + 2, last_occurence(path, '/') - 1);
  full_path[size] = '\0';
  return full_path;
}

char *set_build_path(char *path) {
  if (strcmp(path, ".") == 0) {
    return "build/";
  }
  char *build_path = malloc(strlen(path));

  if (build_path == NULL) {
    fprintf(stderr, "Malloc failed\n");
    return NULL;
  }

  strcpy(build_path, path);
  strcat(build_path, "build/");
  return build_path;
}

int get_compile_settings(program_info_t *settings, int *argc, char **argv) {
  settings->main_path = get_path(argv[0]);
  if (settings->main_path == NULL) {
    fprintf(stderr, "Failed to get path\n");
    return -1;
  }

  settings->build_path = set_build_path(settings->main_path);
  if (settings->build_path == NULL) {
    fprintf(stderr, "Failed to set build_path\n");
    return -1;
  }

  for (unsigned int i = 1; i < (unsigned int)*argc; i++) {
    settings->flags[(i - 1)] = argv[i];
  }
  settings->flag_count = *argc - 1;
  return 0;
}

int is_flag_set(program_info_t *settings, char *flag) {
  for (unsigned int i = 0; i < settings->flag_count; i++) {
    if (strcmp(settings->flags[i], flag) == 0) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  program_info_t *settings = malloc(sizeof(program_info_t));
  if (settings == NULL) {
    fprintf(stderr, "Malloc Failed\n");
    return -1;
  }

  if (get_compile_settings(settings, &argc, argv) != 0) {
    fprintf(stderr, "Failed to get settings\n");
    return -1;
  }

  if (is_flag_set(settings, ONLY_CLEAN_FLAG_SHORT) == 1 ||
      is_flag_set(settings, ONLY_CLEAN_FLAG_LONG) == 1) {

    char clean_build[strlen(settings->build_path) + 8];
    sprintf(clean_build, "rm -rf %s*", settings->build_path);
    system(clean_build);
    return 0;
  }

  if (is_flag_set(settings, CLEAN_BUILD_FLAG_SHORT) == 1 ||
      is_flag_set(settings, CLEAN_BUILD_FLAG_LONG) == 1) {

    char clean_build[strlen(settings->build_path) + 8];
    sprintf(clean_build, "rm -rf %s*", settings->build_path);
    system(clean_build);
  }

  if (is_flag_set(settings, CMAKE_BUILD_FLAG_SHORT) == 1 ||
      is_flag_set(settings, CMAKE_BUILD_FLAG_LONG) == 1) {

    char cmake_build_command[strlen(settings->main_path) +
                strlen(settings->build_path) + 11];
    sprintf(cmake_build_command, "cmake %s -B %s",
            settings->main_path,
            settings->build_path);
    system(cmake_build_command);
  }

  char cmake_compile_command[strlen(settings->build_path) + 15];
  sprintf(cmake_compile_command, "cmake --build %s", settings->build_path);
  system(cmake_compile_command);

  if (is_flag_set(settings, RUN_MAIN_FLAG_SHORT) == 1 ||
      is_flag_set(settings, RUN_MAIN_FLAG_LONG) == 1) {

    char run_main[strlen(settings->build_path) + strlen(MAIN_NAME) + 3];
    sprintf(run_main, "./%s%s", settings->build_path, MAIN_NAME);
    system(run_main);
  }

  if (strcmp(settings->main_path, ".") != 0) {
    free(settings->main_path);
    free(settings->build_path);
  }
  free(settings);
  return 0;
}
