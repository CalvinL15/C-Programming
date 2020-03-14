#include <stdio.h>

int n, S, A[15], W[1024] = {};
void dfs(int index, int A[], int sum) {
	if (index == N) {
		W[sum]++;
		return ;
	}
	dfs(index+1, A, sum);
	dfs(index+1, A, sum+A[index]);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	dfs(0, A, 0);
	while (scanf("%d", &S) == 1)
		printf("%d\n", W[S]);
	return 0;
}
