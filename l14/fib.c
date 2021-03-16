#include <stdio.h>

/* Memoization */
unsigned long long fibmemo[100];

/* fib(n) returns the nth fibonnaci number */
unsigned long long fib(unsigned int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n >= 100) return 0;
  if (!fibmemo[n])
    fibmemo[n] = fib(n-1) + fib(n-2);
  return fibmemo[n];
}

int main() {
  int x;
  while (1) {
    scanf("%d", &x);
    if (x < 0) return 0;
    printf("Fib(%d) = %llu\n", x, fib(x));
  }
}
      
	 
