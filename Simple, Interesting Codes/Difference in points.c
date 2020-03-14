#include <stdio.h>

void behind(int *, int);

int main(void) {
    int array[10];
    int N, i;
    
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &array[i]);
    }
    behind(array, N);
    for (i=0; i<N; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}

/* Write your function behind() here: */
void behind (int *arr, int size){
	int winner = -1;
	int i;
	for (i = 0; i<size; i++){
		if(winner < arr[i])
			winner = arr[i];
	}
	for(i = 0; i<size; i++){
		arr[i] = winner - arr[i];
	}
}
