//TOTIENT MAXIMUM
//this program will TLE for n > 100000
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
	double frac;
	double frac_res = 0;
	int res = 0;
	int i;
	for(i = 2; i<=n; i++){
		for(num = 2; num<i; num++){
			if(GCDchecker(num, i) == 1){
				count++;	
			}
		}
		frac = i / count;
		count = 1;
		if(frac_res < frac){
			frac_res = frac;
			res = i;	
		}
	}
//	printf("%d", count);	
	//optional
//	printf("\n");
//	int i;
//	for(i = 1; i<=count; i++){
//		printf("%d ", saver[i]);
//	}
	printf("%d", res);
	return 0;
}
