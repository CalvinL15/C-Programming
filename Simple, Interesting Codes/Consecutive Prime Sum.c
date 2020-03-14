#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1000000

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
	int prime[SIZE];
	int totalprime[SIZE];
	int cummulative = 2;
	int i;
	for(i = 3; i<1000000; i+=2){
		int temp = IsPrime(i);
		if(temp == 1){
			prime[i] = 1;
			cummulative += i;
			if(cummulative < SIZE)
				totalprime[cummulative] = 1;	
		}
		else prime[i] = -1;	
	}
	int res = 0;
	for(i = 999999; i>2; i-=2){
		if(totalprime[i] == 1 && prime[i] == 1){
			res = i;
			break;
		}
	printf("%d", res);
	return 0; 	
}
