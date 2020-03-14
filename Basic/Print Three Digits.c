#include <stdio.h>
int main(){
  int x;
  scanf("%d", &x);
  if (x >= 100 && x<= 999){ 
  printf("%d\n%d\n%d", (x-(x%100))/100, (x%100 - x%10)/10, x%10);
  } 
           return 0;
           }
