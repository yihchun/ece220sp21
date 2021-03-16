#include <stdio.h>

/* algorithm: recursive
 * split it down the middle
 * sort the left half
 * sort the right half
 * stitch them together
 */

/* msort sorts the first len elements of array in ascending order
 * and requires the caller to provide temporary space in tmp 
 * of size at least len
 */
void msort(int *array, int *tmp, int len) {
  int llen = len/2;
  int rlen = len-llen;
  int *middle = array + llen;
  int tidx, lidx, ridx;
  
  if (len <= 1) return; /* arrays of length 0 and 1 are sorted */
  msort(array, tmp, llen);
  msort(middle, tmp, rlen);
  
  for (tidx = lidx = ridx = 0; (lidx < llen) || (ridx < rlen); tidx++) {
    if (lidx == llen) { /* ran out of left elements, pick from right */
      tmp[tidx] = middle[ridx++];
    } else if (ridx == rlen) { /* ran out of right elements, pick from left */
      tmp[tidx] = array[lidx++];
    } else if (array[lidx] > middle[ridx]) { /* right side smaller */
      tmp[tidx] = middle[ridx++];
    } else { /* left side smaller */
      tmp[tidx] = array[lidx++];
    }
  }

  for (tidx = 0; tidx < len; tidx++)
    array[tidx] = tmp[tidx];
}

#define LEN 16
int main() {
  FILE *fp = fopen("/dev/urandom", "r"); /* don't worry about this */
  int arr[LEN];
  int tmp[LEN];
  int i;

  for (i=0; i<LEN; i++) {
    arr[i] = fgetc(fp); /* don't worry about this */
  }

  for (i=0; i<LEN; i++)
    printf("%d ", arr[i]);
  printf("\n");
  msort(arr, tmp, LEN);
  for (i=0; i<LEN; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
