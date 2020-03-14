//10001st prime
#include <math.h>
#include <stdlib.h>
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
	int checker = 1;
	int i = 3;
	while(checker < 10001){
		int temp = IsPrime(i);
		if(temp == 1)
			checker++;
		i += 2;	
	}
	printf("%d", i-2);
	return 0;
}

