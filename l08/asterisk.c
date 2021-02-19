#include <stdio.h>

int main() {
  int in = -1, i;
  do {
    printf("Enter the number of * to print out (1-10), enter 0 to exit: ");
    scanf("%d", &in);
    if (in > 0 && in <= 10) {
      for (i=0; i<in; i++)
	printf("*");
      printf("\n");
    }
  } while (in != 0);
  printf("Program exit.\n");
  return 0;
}
