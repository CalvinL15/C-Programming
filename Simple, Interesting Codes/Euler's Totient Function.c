//Euler's Totient Function

#include <stdio.h>

int GCDchecker(int num, int n){
	while(n > 0 && num > 0){
		if(n > num)
			n -= num;
		else num -= n;
	}
	if(n == 0){
		return num;
	}
	else return n;
}

int main(){
	int n;
	scanf("%d", &n);
	int count = 1;
	int num;
	int saver[n];
	saver[1] = 1;
	for(num = 2; num<n; num++){
		if(GCDchecker(num, n) == 1){
			count++;
		 //optional, if you want to print all of the numbers
		 	saver[count] = num;			
		}
	}
	printf("%d", count);	
	//optional
	printf("\n");
	int i;
	for(i = 1; i<=count; i++){
		printf("%d ", saver[i]);
	}
	return 0;
}
