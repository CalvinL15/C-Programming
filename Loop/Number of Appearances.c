#include <stdio.h>
int main(){
	char N[1], M[6];
	scanf("%s%s", N, M);
	int count = 0;
	int i;
	for (i = 0; i < 6; i ++){
		if(N[0] == M[i] && N[1] == M[i+1])
		count ++;
	}
	printf("%d\n", count);
	return 0;	
}
