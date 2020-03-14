#include <stdio.h>
int main(){
  int a, b, c, d, e;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  d = 2*(a*b + a*c + b*c);
  e = a*b*c;
  printf("%d\n%d", d, e);
  return 0;
}
