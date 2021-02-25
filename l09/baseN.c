#include <stdio.h>
#include <math.h>

int getDigitBaseN(int number, int N){
  int digit, res;
  res = 1;
  digit = 0;
  while (res <= number) {
    res *= N;
    digit++;
  }
  return digit;
}

void printBaseN(int number, int N){
  int digit = getDigitBaseN(number, N);
  int i;
  int divby = 1;
  
  for (i=0; i<(digit-1); i++)
    divby *= N;
  for (i=0; i<digit; i++) {
    printf("%d", (number / divby) % N);
    divby /= N;
  }
  printf("\n");
}

int main(){
    int number, N;
    printf("type number: ");
    scanf("%d", &number);
    printf("type base N: ");
    scanf("%d", &N);

    printf("number of digits: %d\n", getDigitBaseN(number, N));
    printBaseN(number, N);

    return 0;
}
