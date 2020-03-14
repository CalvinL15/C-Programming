#include <stdio.h>
int main(){
  int a = 0;
  int b = 0;
  char c[4];
  char d[4];
  int i;
  int j;
  scanf("%s %s", c, d);
  
  for (i = 0; i < 4; i++){
    if ( c[i] == d[i] )
      a++;
  }
  
  for ( i = 0; i < 4; i++){
    for ( j = 0; j < 4; j++){
      if(c[i] == d[j] && i != j)
        b++;
    }
  }
  printf("%dA%dB\n", a, b);
  return 0;
}
