#include <stdio.h>
int main(){
  int total, leg, tails;
  scanf("%d%d%d", &total, &leg, &tails);
  if (tails > total)
    printf("0");
  else if (( 4*total - leg/2 - 2*tails) < 0 || leg%2 != 0)
    printf("0");
  else if(( -4*total + leg/2 + 3*tails) < 0 || leg%2 != 0)
    printf("0");
  else {
    printf("%d\n",4*total-leg/2-2*tails);
    printf("%d\n",-4*total+leg/2+3*tails);
    printf("%d\n",total-tails);
    }
  return 0;
}
