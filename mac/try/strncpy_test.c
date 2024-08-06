#include <string.h>
#include <stdio.h>

int main()  {
  char *test = "String to test";
  unsigned int size = strlen(test) - 2;
  char newString[size + 1];
  strncpy(newString, test+2, size);
  newString[size] = '\0';

  printf("String: %s\nsize: %d\n", newString, size);
  return 0;
}
