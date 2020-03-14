#include <stdio.h>
int main() {
  int x, a;
  scanf("%d", &x);
  if (x <= 0){
    a = -100;
    printf("%d", a);
  }
  else {
    a = 0;
  if (x % 3 == 0){
      a += 3;
    }
   if (x % 5 == 0){
      a += 5;
    }
    if ( x > 100 && x < 200){
      a += 50;
    }
    else{
     a -= 50;
    }
  printf("%d", a);
    }
  return 0;
}
