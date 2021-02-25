#include <stdio.h>

int maxk(int n){
  if (n <= 1) return 0;
  return 1+maxk(n/2);
  /*
  int sum=1, k=0;
  while (sum <= n) {
    sum *= 2; k++;
  }
  return k-1;
  */

  int k = 0;
  while (n/2 > 0) {
    n /= 2;
    k++;
  }
  return k;
}

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Maximum k that satisfies 2^k<=n is %d\n", maxk(n));
    return 0;
}
