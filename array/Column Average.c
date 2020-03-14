#include <stdio.h>

int main(){
	int r, c;
	int total[100];
	int i, j, num;
	for (i = 0; i<100, i++){
		total[i]=0;
	}
	for (i = 0; i<r; i++)
	{ for (j=0; j<c; j++)
	{ scanf("%d", &num);
		total[j] += num;
	}
	}
	
	for(i = 0; i<c; i++)
	{printf("%d\n", total[i]/r);
	}
	return 0;
}
