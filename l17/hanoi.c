#include <stdio.h>
/* Goal output:
 * hanoi(1,...)
 * Move size 1 from A to C
 *
 * hanoi(2,...)
 * Move size 1 from A to B <- recursive
 * Move size 2 from A to C
 * Move size 1 from B to C <- recursive
 */

/* moves a stack [1..maxsz] from start to end using intermediate */
void hanoi(unsigned int maxsz, char start, char end, char intermediate) {
  if (!maxsz) return;
  hanoi(maxsz-1, start, intermediate, end);
  printf("Move size %u from %c to %c\n", maxsz, start, end);
  hanoi(maxsz-1, intermediate, end, start);
}

int main() {
  int x;
  while (1) {
    scanf("%d", &x);
    if (x<0) return 0;
    hanoi(x,'A','B','C');
  }
}
  
