#include <stdio.h>
#include "Arvin.h"

/*int query(int pancake_seq, int tea_seq){
    int p_sugar = pancake_seq;
    int t_sugar = tea_seq+1;
    if(p_sugar>t_sugar)
        return 1;
    if(p_sugar==t_sugar)
        return 0;
    if(p_sugar<t_sugar)
        return -1;
}*/

int main(){
	int N;
	scanf("%d", &N);
	int pancake_seq[N+1];
	int tea_seq[N+1];
	int i;
	for(i = 0; i<N; i++){
		scanf("%d", &pancake_seq[i]);
	}
	for(i = 0; i<N; i++){
		scanf("%d", &tea_seq[i]);
	}
	int j;
	int pancake_sorted[N+1];
	int tea_sorted[N+1];
	int count = 0;
	int key;
	for(i = 0; i<N; i++){
		for(j = 0; j<N; j++){
			int temp = query(pancake_seq[i], tea_seq[j]);
			if(temp == 1)
				count++;
			if(temp == 0)
				key = tea_seq[j];	
		}
		pancake_sorted[count] = pancake_seq[i];
		tea_sorted[count] = key;	
		count = 0;
	}
	for(i = 0; i<N; i++){	
		printf("%d %d", pancake_sorted[i], tea_sorted[i]);
		if(i != N-1)
			printf("\n");
	}
	return 0;
}
