#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int IsPrime(int num){
	int divisor;
	int flag = 0;
	for(divisor = 2; divisor <= sqrt(num); divisor++){
		if(num % divisor == 0){
			flag = 1;
			break;
		}
		else{
			if(divisor % 2 == 1)
				divisor++;	
		} 	
	}
	if(flag == 0)
		return 1;
	return 0;		
}

int main(){
	int scope;
	int count = 0;
	scanf("%d", &scope);
	int i;
	for(i = 2; i<=scope; i++){
		int temp = IsPrime(i);
		count += temp;
	}
	printf("%d", count);
	return 0;
}
