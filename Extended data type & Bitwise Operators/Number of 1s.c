#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int count = 0;
		while(n){
			if(n&1 == 1)
				count++;
			n >>= 1;		
		}
		printf("%d\n", count);
	}
	return 0;
}
