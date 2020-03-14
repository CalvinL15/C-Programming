#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define inf 999999

int matrix[100][100];
int cnt = 0;
int BFS(int currentVertice, int beginVertice, int length, int maxLength, int *visited, int** list, int N);
int tempsav[100] = {0};
int max = -1;

int findlongestlength(int **cycle, int N){
	int length = 0;
	int *visited = (int*)calloc(N+1, sizeof(int));
	int *tempcycle = (int*)malloc((N + 2) * sizeof(int));
	for(int curver = 0; curver < N; curver++){
		tempcycle[0] = curver;
		int curlen = BFS(curver, curver, 0, length, visited, &tempcycle, N, 0);
		if(curlen > length){
			length = curlen;
			for(int i = 0; i<length+1; i++){
				(*cycle)[i] = tempcycle[i];
			}
		}
	}
	free(visited);
	return length;
}
int flag = 0;
int BFS(int currentVertice, int beginVertice, int length, int maxLength, int *visited, int** list, int N, int k)
{
	int newLength = maxLength;
	visited[currentVertice] = 1;
//	tempsav[0] = beginVertice;
	for (int nextVertice = 0; nextVertice < N; nextVertice++)
	{
		if (matrix[currentVertice][nextVertice] == 1)
		{
			if (nextVertice == beginVertice && length > 1 && length + 1 > maxLength)
			{
				newLength = length + 1;
				for(int i = 0; i<cnt; i++){
					(*list)[i+1] = tempsav[i];
				}
				(*list)[cnt+1] = nextVertice;
			}
			else if (!visited[nextVertice])
			{	
				tempsav[cnt] = nextVertice;
				cnt++;
				k++;
			//	(*list)[length+1] = nextVertice;
				newLength = BFS(nextVertice, beginVertice, length + 1, newLength, visited, list, N, k);
			}
		}
	}
/
	cnt = k;
	visited[currentVertice] = 0;
	return newLength;
}

void PrintCycle(int* cycle, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d ", cycle[i]);
	}
	printf("\n");
}

int main(){
	int N, E;
	scanf("%d %d", &N, &E);
	int* cycle = (int*)malloc((N + 2) * sizeof(int));
	int e1, e2;
	for(int i = 0; i<=N; i++)
		for(int j = 0; j<=N; j++)
			matrix[i][j] = inf;
	for(int i = 0; i<E; i++){
		scanf("%d %d", &e1, &e2);
		matrix[e1][e2] = 1;
		matrix[e2][e1] = 1;	
	}
	int len = 0;
	len = findlongestlength(&cycle, N);
	printf("%d\n", len);
//	for(int i = 0; i<10; i++)
//		printf("%d ", tempsav[i]);
//	printf("\n");	
	for(int i = 0; i<len; i++)
		printf("%d ", cycle[i]);
}
