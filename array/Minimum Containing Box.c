#include <stdio.h>

int main(){
	int a[100];
	int b[100];
	int lowesta = 0;
	int lowestb = 0;
	int highesta = 0;
	int highestb = 0;
	int i = 0;
	int count = 0;
	while(scanf("%d %d", &a[i], &b[i]) != EOF){
		count++;
		if(count == 1){
			lowesta = a[i];
			lowestb = b[i];
			highesta = a[i];
			highestb = b[i];
		}
		if(a[i] <= lowesta)
			lowesta = a[i];
		if(a[i] >= highesta)
			highesta = a[i];
		if(b[i] >= highestb)
			highestb = b[i];
		if(b[i] <= lowestb)
			lowestb = b[i];			
	}
	int length = highesta - lowesta;
	int width = highestb - lowestb;
	printf("%d", length * width);
	return 0;
}

