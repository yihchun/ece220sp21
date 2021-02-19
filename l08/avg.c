#include <stdio.h>

int main(){
    int n, i, num, sum=0;
    double average;
    printf("Enter how many numbers to input: ");
    scanf("%d", &n);

    /* Your code here */
    printf("Enter the numbers\n");
    for (i=0; i<n; i++) {
      scanf("%d", &num);
      sum += num;
    }
    average = sum/(double)n;

    printf("The average of the numbers: %lf\n", average);
}
