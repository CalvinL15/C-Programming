#include <stdio.h>

int k, N, M;
int A[20];
int res = 0;

void recurse(int cur_k, int cur_M, int idx, int ocur_k, int ocur_m){
	if(cur_k >= k && cur_M <= M && ocur_k != cur_k && ocur_m != cur_M)
		res++;
	if(cur_k == N || idx == N)
		return;
	ocur_k = cur_k, ocur_m = cur_M;	
	recurse(cur_k+1, cur_M+A[idx], idx+1, ocur_k, ocur_m);
	recurse(cur_k, cur_M, idx+1, ocur_k, ocur_m);		
}

int main(){
	scanf("%d %d %d", &k, &N, &M);
	for(int i = 0; i<N; i++)
		scanf("%d", &A[i]);
	recurse(0, 0, 0, 0, 0);
	printf("%d", res);
	return 0;	
}
