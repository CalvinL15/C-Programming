#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, m;
	scanf("%d %d", &N, &m);
	int arr[10001] = {0};
	for(int i = 0; i<N; i++){
		scanf("%d ", &arr[i]);
	}
	int sum = 0, max = 0, min = -1;
	for(int i = 0; i<m; i++){
		for(int j = 0; j<N; j++){
			if(arr[j] % m == i){
				sum += arr[j];
				if(max < arr[j])
					max = arr[j];
				if(min == -1 || min > arr[j])
					min = arr[j];	
			}	
		}
		printf("%d %d %d", sum, max, min);
		sum = 0, max = 0, min = -1;
		if(i != m-1)
			printf("\n");
	}
}
