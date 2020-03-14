#include <stdio.h>
#define A 40000
#define B 10000
#define C 4000
#define D 1000
#define E 200

int main(){
	int special[3], first[3];
	int i;
	for (i = 0; i < 3; i++)
		scanf("%d", &special[i]);
	for (i = 0; i < 3; i++)
		scanf("%d", &first[i]);
	int total = 0;
	int a;
	while(scanf("%d", &a) != EOF){
		for (i = 0; i < 3; i++){
			if (a == special[i])
				total += 2000000;
		}
		for (i = 0; i < 3; i++){
			if (a == first[i])
				total += 200000;
			if (a % 1000 == first[i] % 1000 && a % 10000 != first[i] % 10000)
				total += E;
			if (a % 10000 == first[i] % 10000 && a % 100000 != first[i] % 100000)
				total += D;
			if (a % 100000 == first[i] % 100000 && a % 1000000 != first[i] % 1000000)
				total += C;	
			if (a % 1000000 == first[i] % 1000000 && a % 10000000 != first[i] % 10000000)
				total += B;	
			if (a % 10000000 == first[i] % 10000000)
				total += A;	
		}
	}
	printf("%d", total);
	return 0;	
}
	
