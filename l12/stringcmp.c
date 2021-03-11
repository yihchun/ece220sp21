#include <stdio.h>

int stringcmp(const char *str1, const char *str2){
  while (*str1) {
    if (*str1 > *str2) return 1;
    if (*str1 < *str2) return -1;
    str1++; str2++;
  }
  return 0;
  /* "cab" "cabal" */

  /*
  int i;
  for (i=0; str1[i] && (str1[i] == str2[i]); i++)
    ;

  if (str1[i] > str2[i]) return 1;
  if (str1[i] < str2[i]) return -1;
  return 0;
  */
}

int main(){
    char *str1 = "ABC";
    char *str2 = "ABCD";

    int ret = stringcmp(str1, str2);
    if(ret == 0)
        printf("%s and %s are the same. \n", str1, str2);
    else if(ret <0)
        printf("%s is less than %s. \n", str1, str2);
    else
        printf("%s is greater than %s. \n", str1, str2);


    return 0;
}
