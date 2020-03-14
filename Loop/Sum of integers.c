#include <stdio.h>

int main(){
	int sum = 0;
	int count;
	scanf("%d", &count);
	int i;
	for (i = 0; i <= count; i++){
		sum += i;
	}
	printf("%d", sum);
	return 0;
}
