#include <stdio.h>


void oddeven(int *arr, unsigned int count){
  int odd[count], even[count], oddloc = 0, evenloc = 0, i;

  for (i=0; i<count; i++) {
    if (arr[i]%2) {
      odd[oddloc++] = arr[i];
    } else {
      even[evenloc++] = arr[i];
    }
  }

  for (i=0; i<count; i++) {
    if (oddloc > i) {
      arr[i] = odd[i];
    } else {
      arr[i] = even[--evenloc];
    }
  }
}

int main(){
    int arr[50];
    int i, N;
    for(i=0; i<50; i++){
        scanf("%d", arr+i);
        if(arr[i] == -1)
            break;
    }
    N = i;
    oddeven(arr, N);
    for(i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
