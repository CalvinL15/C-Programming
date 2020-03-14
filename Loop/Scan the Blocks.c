#include <stdio.h>
#include <limits.h>

int main(){
	int N;
	int track = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	int num, i;
	while(scanf("%d", &N) != EOF){
		while(scanf("%d", &num) != EOF){
			if(max < num)
				max = num;
			if(min > num)
				min = num;
			N--;
			if(N == 0)
				break;		
		}
		if(N == 0){
				if(track != 0)
					printf("\n%d", max);
				else{
					printf("%d", max);
					track++;
				}	
		}
		else printf("\n%d", min);
		max = INT_MIN, min = INT_MAX;
	}
}
