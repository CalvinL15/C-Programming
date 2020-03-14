#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) {int t; t = a, a = b, b = t;}
/*void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} */

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;    
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
}

int flag = 0;
int permute(int A[], int n) {
	for (int i = n-2; i >= 0; i--) {
		if (A[i] < A[i+1]) {
			int j = i+1;
			while (j < n && A[j] > A[i])	
				j++;
			j--;
			swap(A[i], A[j]);
			for (int p = i+1, q = n-1; p < q; p++, q--)
				swap(A[p], A[q]);
			return 1;
		}
	}
	return 0;
}

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main(){
	int N; 
	scanf("%d", &N);
	int arr[N];
	for(int i = 0; i<N; i++)
		scanf("%d", &arr[i]);
	quickSort(arr, 0, N-1);
	for(int i = 0; i<N; i++)
		printf("%d ", arr[i]);
	while(permute(arr, N)){
		printf("\n");
		for(int i = 0; i<N; i++)
			printf("%d ", arr[i]);
	}	
}
