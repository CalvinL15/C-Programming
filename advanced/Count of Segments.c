#include <stdio.h>

int main(){
	int N;
	int count = 0;
	int number, i;
	while(scanf("%d", &N) != EOF){
		int previous;
		for(i = 0; i < N; i++){
			scanf("%d", &number);
			if ((i == 0)  || (number != previous && (number == 1 || number == 0)))
                count++;
            previous = number;
			}
		}
	printf("%d\n", count);
	return 0;
}
