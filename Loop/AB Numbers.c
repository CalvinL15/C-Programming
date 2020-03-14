#include <stdio.h>
int main(){
  char a[4], b[4];
  int countA = 0, countB = 0;
  scanf("%s%s", a, b);
  int i, j;
  for (i = 0; i < 4; i++){
    if (a[i] == b[i])
      countA++;
  }
  for (i = 0; i < 4; i++){
    for (j = 0; j < 4; j++){
      if (a[i] == b[j] && i != j)
        countB++;
    }
  }
  printf("%dA%dB\n", countA, countB);
  return 0;
}
