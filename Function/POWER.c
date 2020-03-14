#include <stdio.h>
#include <math.h>
double pow(double x, double y);
float powf(float x, float y);
long double powl(long double x, long double y);
int main(){
  int x, y;
  scanf("%d%d", &x, &y);
 printf("%d", (int) pow(x, y));
  return 0;
}
