#include <stdio.h>

void test(const int x[][3]) {
  int i, j;
  for (i=0; i<4; i++) {
    for (j=0; j<3; j++) {
      printf("%d ", x[i][j]);
    }
    printf("\n");
  }
    
}

int sumBound(const int *array, int row, int col){
  int i, j;
  int sum = 0;
  for (i=0; i<row; i++)
    for (j=0; j<col; j++) {
      if ((i == 0) || (j == 0) || (i == row-1) || (j == col-1))
	sum += *array; /* array[i*col+j] if you don't increment array */

      array++;
    }

  /* rows and cols separately
  for (i=0; i<col; i++) {
    sum += array[i] + array[(row-1)*col+i];
  }
  for (i=1; i<row-1; i++) {
    sum += array[i*col] + array[i*col+col-1];
  }
  */
  /* Clockwise traversal
  i = 0;
  for (j=0; j<col-1; j++) {
    sum += array[i*col+j];
  }
  j = col-1;
  for (i=0; i<row-1; i++) {
    sum += array[i*col+j];
  }
  i = row-1;
  for (j=col-1; j>0; j--) {
    sum += array[i*col+j];
  }
  j = 0;
  for (i=row-1; i>0; i--) {
    sum += array[i*col+j];
  }
  */
  return sum;
}
int main(){
    int array[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    printf("The sum of bounadry is %d.\n", sumBound(&array[0][0], 4, 3));
    test(array);
    return 0;
}
