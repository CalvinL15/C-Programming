//Even Fibonacci Numbers

#include <stdio.h>

int main(){
	int a = 0, b = 1, c = 0;
	int i;
	int sum = 0;
	int n;
	scanf("%d", &n);
	while (c <= n){
		c = a+b;
		a = b;
		b = c;
		if(c % 2 == 0)
			sum += c;
	}
	printf("%d", sum);
	return 0;
}
