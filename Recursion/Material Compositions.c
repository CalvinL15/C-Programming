#include <stdio.h>

int A[3], B[3], C[3];
int flag = 0;
void recurse(int A[], int B[], int C[], int resA, int resB, int resC, int tA, int tB, int tC){
	if(tA == resA && tB == resB && tC == resC){
		flag = 1;
		return;
	}
	else if(tA > resA || tB > resB || tC > resC)
		return;
	recurse(A, B, C, resA, resB, resC, tA+A[0],tB+B[0], tC+C[0]);
	recurse(A, B, C, resA, resB, resC, tA+A[1],tB+B[1], tC+C[1]);
	recurse(A, B, C, resA, resB, resC, tA+A[2],tB+B[2], tC+C[2]);
}

void scanfunction(int n){
	if(n == 0)
		return;
	int resA, resB, resC;
	scanf("%d %d %d", &resA, &resB, &resC);
	recurse(A, B, C, resA, resB, resC, 0, 0, 0);
	if(flag == 1) printf("yes\n");
	else printf("no\n");
	flag = 0;
	scanfunction(n-1);	
}

int main(){
	scanf("%d %d %d", &A[0], &B[0], &C[0]);
	scanf("%d %d %d", &A[1], &B[1], &C[1]);
	scanf("%d %d %d", &A[2], &B[2], &C[2]);
	int n;
	scanf("%d", &n);
	scanfunction(n);
	return 0;
}
