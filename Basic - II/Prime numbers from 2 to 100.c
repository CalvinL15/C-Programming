#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int p;
	int i;
	int counter = 0;
	int primenumbers[1000];
	int towhatnumber;
	scanf("%d", &towhatnumber);
	bool isPrime;
	for(p = 1; p <= towhatnumber; p++){
		if(p == 1 || (p != 2 && p%2 == 0))
			isPrime = false; 
		else isPrime = true;
		for(i = 1; isPrime && p/primenumbers[i] >= primenumbers[i]; i++){
			if(p % primenumbers[i] == 0)
				isPrime = false;			
				
		}
		if (isPrime == true){
			primenumbers[counter] = p;
			counter++;
		}
	}
	for(i = 0; i < counter; i++){
		printf("%d\n", primenumbers[i]);
	} 
	return 0;
}
