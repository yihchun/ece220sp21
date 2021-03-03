#include <stdio.h>

unsigned int bindigit(unsigned int dec) {
  int ret = 1;
  while (dec > 1) {
    dec /= 2;
    ret++;
  }
  return ret;
}

void dec2bin(unsigned int *arr, int count, unsigned int dec) {
  int i;

  for (i=0; i<count; i++) {
    arr[i] = dec % 2;
    dec /= 2;
  }
}

int main(){
    unsigned int dec;
    printf("Input a decimal number: ");
    scanf("%d", &dec);

    unsigned int N, arr[32];
    int i;
    N = bindigit(dec);
    printf("Number of digit in binary: %d\n", N);

    dec2bin(arr, N, dec);
    for(i=N-1; i>=0; i--)
        printf("%d", arr[i]);
    printf("\n");
    return 0;
}
