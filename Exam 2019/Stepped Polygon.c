#include <stdio.h>

int main(){
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	int peri = 2*(a+b+c+d+e+f);
	int volume = a*(b+d+f) + c*(d+f) + e*f;
	printf("%d %d", peri, volume);
	return 0;
}
