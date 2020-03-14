#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
	int num;
	int i = 0;
	int flag = 0;
	int result = 1;
	while(flag == 0){
		i++;
		num = i * (i+1) / 2;
		int numtemp = num;
		int j = 2, temp;
		while(numtemp > 1){
			temp = IsPrime(j);
			int count = 0;
			if(temp == 1){
				while(numtemp%j == 0){
					count++;
					numtemp /= j;
				}	
			}
			result *= (count+1);
			j++; 
		}
		if(result > 500){
			flag = 1;
			printf("%d", num);
		}
		else result = 1;
	}
	
	
	
	
	
	
	
	
	
	
	
}
