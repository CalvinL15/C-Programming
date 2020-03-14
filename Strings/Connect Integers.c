#include <stdio.h>
#include <stdlib.h>

int main(){
	char digits[20];
	int max = -1;
	int LSD = -1, MSB = -1;
	int len = 0;
	int cur_length = 0;
	while(scanf("%s", digits) != EOF){
		len = strlen(digits);
		LSD = digits[0] - '0';
		if(LSD == MSB)
			cur_length += len;
		else{
			cur_length = 0;
			cur_length += len;
		}
		if(cur_length > max)
			max = cur_length;
		MSB = digits[len-1] - '0';		
	}
	printf("%d", max);
	return 0;
}
