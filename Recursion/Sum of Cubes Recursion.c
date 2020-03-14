#include <stdio.h>
int sum(int n){
if (i == 0){
	return 0;
}
if (i == 1){
	return 1;
}
	return sum(n-1) + n*n*n;
}
	
int main(){
	int n;
	scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}

