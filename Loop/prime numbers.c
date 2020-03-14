#include <stdio.h>
#include <stdlib.h>

int main()
{
	int p;
	int i;
	int primenumbers[100];
	
	for(p = 2; p <= 100; p = p + 2){
		for(i = 1; p/primenumbers[i] >= primenumbers[i]; i++){
			if(p % primenumbers[i] == 0)
				break;
		}
		if(primenumbers[i]>p/primenumbers[i])
			printf("%d\n", p);	
	}
	return 0;
}
