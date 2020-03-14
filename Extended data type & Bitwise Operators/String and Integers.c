#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int task;
	scanf("%d", &task);
	char string[100000];
	if(task == 0){
		scanf("%s", string);
		int len = strlen(string);
		int penanda = 0;
		unsigned long long int res = 0;
		for(int i = 0; i<len; i++){
			penanda++;
			res<<=8;
			res+=string[i];
			if(penanda == 8 || i == len-1){
				if(penanda == 8)
					penanda = 0;
				else if(i == len-1){
					res<<=((8-penanda)*8);
				}	
				printf("%llu\n", res);
				res = 0;	
			}
		}
		if(penanda == 0) printf("0");
	}
	else{
		int N;
		scanf("%d", &N);
		unsigned long long int bignum;
		int F = 0, shiftflag = 64;
		for(int i = 0; i<N; i++){
			char str[8];
			scanf("%llu", &bignum);
			for(int j = 0; j<8; j++){
				shiftflag -= 8;
				str[F] = (bignum >> shiftflag) - ((bignum >>shiftflag+8) << 8);
				F++;
			}
			shiftflag = 64, F = 0;
			printf("%s", str);
		}
	}
}
