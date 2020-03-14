#include <stdio.h>
int main(){
  int a, b, c, d, e, f;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  printf("%d\n", c+e-a);
  printf("%d\n", d+f-b);
  printf("%d\n", a+e-c);
  printf("%d\n", b+f-d);
  printf("%d\n", a+c-e);
  printf("%d\n", b+d-f);
  return 0;
}
