#include <stdio.h>
#include <string.h>

int main(){
	char longnum[1001];
	scanf("%s", longnum);
	long long int result = 0;
	long long int temp = 1;
	int end = 12;
	int start = 0;
	int i;
	while(end < 1000){
		for(i = start; i<=end; i++){
			temp *= (longnum[i] - '0');
		}
		if(temp > result)
			result = temp;
		start++, end++;
		temp = 1;		
	}
	printf("%lld", result);
}
