#include <stdio.h>
int main(){
	int even[1000], odd[1000];
	int number;
	int n;
	int read;
	int e = 0;
	int o = 0, i;
	scanf("%d", &n);
	for(i = 0; i<n; i++){
		scanf("%d", &read);
		if(read % 2 == 1){
		
			odd[o] = read;
			o++;
		}
		else {
			even[e] = read;
			e++;
		}
	}
	for(i = 0; i<o; i++){
		if(i == o-1)
			printf("%d\n", odd[i]);
		else printf("%d ", odd[i]);	
	}
	for(i = 0; i<e; i++){
		if(i == e-1)
			printf("%d", even[i]);
		else printf("%d ", even[i]);	
	}
	return 0;
}
