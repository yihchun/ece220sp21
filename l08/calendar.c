#include <stdio.h>

/*
yhu@YHmb ece220sp21/l08 % cal 9 2020
   September 2020
Su Mo Tu We Th Fr Sa
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30
*/

int main(){
    int date;
    printf("Enter a date in September 2020: ");
    scanf("%d", &date);

    /*
    if (date <=0 || date > 30) {
      printf("Invalid date!\n");
      return 0;
    }
    */
    
    switch ((date>0 && date <= 30) * (((date-1)%7)+1)) {
    case 1: printf("9/%d/2020 is Tuesday.\n", date); break;
    case 2: printf("9/%d/2020 is Wednesday.\n", date); break;
    case 3: printf("9/%d/2020 is Thursday.\n", date); break;
    case 4: printf("9/%d/2020 is Friday.\n", date); break;
    case 5: printf("9/%d/2020 is Saturday.\n", date); break;
    case 6: printf("9/%d/2020 is Sunday.\n", date); break;
    case 7: printf("9/%d/2020 is Monday.\n", date); break;
    case 0: printf("Invalid date!\n");
    }
    
    return 0;
}
