#include <stdio.h>
int main(){
	int n;
	int array[1000];
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}
	for(i = n-1; i >= 0; i--){
		if(i == 0)
			printf("%d", array[i]);
		else printf("%d ", array[i]);	
	}
	printf("\n");
	return 0;
}
