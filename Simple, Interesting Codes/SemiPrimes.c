#include <stdio.h>

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
	int count = 1;
	int i, temp;
	for(i = 3; i<100000000; i+=2){
		temp = IsPrime(i);
		if(temp == 1)
			count++;
	}
	long long result = count*(count-1)/2;
	printf("%lld", result);
} 
