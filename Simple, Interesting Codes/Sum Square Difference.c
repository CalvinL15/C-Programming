#include <stdio.h>
#include <stdlib.h>

int main(){
	int sumofsquares = 0;
	int squareofsum = 0;
	int i;
	for(i = 1; i<=100; i++){
		sumofsquares += i*i;
		squareofsum += i;
	}
	squareofsum *= squareofsum;
	int dif = abs(squareofsum - sumofsquares);
	printf("%d\n", dif);
	//ALTERNATIVE WAY
	int j;
	int res = 0;
	for(i = 1; i<=99; i++)
		for(j = i+1; j<=100; j++){
			res += 2*i*j;
		}
	printf("%d", res);
	return 0;	
}
