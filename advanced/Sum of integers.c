#include <stdio.h>

int main() {
    int i, j, toto = 0;
    int sum = 0;
    int value;
    while (scanf("%d\n", &i) != EOF) {
       toto++;
	   for (j = 1; j<= toto; j++)
	   	sum = sum + i;
  	}
  	printf("%d", sum);
    return 0;
}
