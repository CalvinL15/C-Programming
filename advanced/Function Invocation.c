#include <stdio.h>
 
int h(int x) {
    if (x < 2)    return -1;
    return 2 + h(x-1) - h(x-2);
}  
int g(int x) {
      if (x <= 2) return x*x -1;
      return 2;
}
 
int f(int x) {
  if( x > h(x)) return f(x-1)-h(x);
  if( x < h(x)) return f(g(x))-g(x);
  return 1;
}
 
int main(){
  int x;
  scanf("%d", &x);
  printf("%d", f(x));
  return 0;
}

