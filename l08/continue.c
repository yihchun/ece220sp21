#include <stdio.h>
int main() {
  int x;
  do {
    scanf("%d", &x);
    if (x <= 0) continue;
    printf("not continued\n");
  } while (printf("in cond\n") && x);
}
