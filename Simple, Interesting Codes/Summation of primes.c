#include <stdio.h>
#include <math.h>
#define LIM 2000000

typedef long long int lld; 

int IsPrime(int num){
	int i;
	if(num % 2 == 0)
		return 0;
	for(i = 3; i<=sqrt(num); i+=2){
		if(num % i == 0)
			return 0;
	}
	return 1;
}

int main(){
	lld result = 2;
	int i;
	for(i = 3; i < LIM; i+=2){
		if(IsPrime(i) == 1)
			result += i;
	}
	printf("%lld", result);
	return 0;
}
