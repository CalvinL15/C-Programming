//the sum of multiples of 3 and 5 
//PROBLEM 1 of projecteuler.net

#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int sum = 8;
	int i;
	for(i = 6; i<n; i++){
		if(i % 3 == 0 || i % 5 == 0)
			sum += i;
		else continue;	
	}
	printf("%d", sum);
	return 0;
} 
