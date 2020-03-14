#include <stdio.h>
 
int main(){
  int a;
  int count0 = 0;
  int count1 = 0;
  int count2 = 0;
  int b;
  scanf("%d", &a);
  for (int i = 1; i <= a; i++){
  	scanf("%d", &b);
    if (b % 3 == 0)
      count0 ++;
    else if (b%3 == 1)
      count1 ++;
    else if (b%3 == 2)
      count2 ++;
  }
  printf("%d %d %d", count0, count1, count2);
  return 0;
}
