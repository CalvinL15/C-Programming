#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	scanf("%d", &N);
	char dict[N][200];
	for(int i = 0; i<N; i++)
		scanf("%s", dict[i]);
	int Q;
	char words[200];
	for(int i = 0; i<Q; i++){
		if(i != 0)
			printf("\n");
		scanf("%s", words);
		int res = 0;
		for(int j = 0; j<N; j++){
			if(strstr(dict[j], words) != NULL)
				res++;
		}
		printf("%d", res);
	}
	return 0;	
}
