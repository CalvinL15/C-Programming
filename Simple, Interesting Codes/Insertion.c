#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
typedef long long int ll;
int main(){
	int S;
	scanf("%d", &S);
	long long int result = 0;
	long long int data[S];
	int i, j;
	for(i = 0; i<S; i++){
		scanf("%lld", &data[i]);
	}
	ll min_idx;
	int count = 0;
	int temp;
	for (i = 0; i < S-1; i++) 
    { 
       
        min_idx = i; 
        for (j = i+1; j < S; j++) 
          if (data[j] < data[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&data[min_idx], &data[i]);
        result += (data[min_idx]*(min_idx-i) + data[i]*(min_idx-i)); 
    }
    printf("%lld", result%(1000000007)); 
}
