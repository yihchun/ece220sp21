#include <stdio.h>

int main() {
  char goodbye[10] = "Hello";
  char greeting[10];
  int i;
  for (i=0; i<10; i++)
    greeting[i] = goodbye[i];

  return 0;
}
