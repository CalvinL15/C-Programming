#include <limits.h>

int evaluate_f(int *iptr[], int n, int *index){
	int max = INT_MIN;
	int s = 0;
	for(int i = 0; i<n; i++){
		int res = iptr[i][0]*4- iptr[i][1]*6;
		if(res > max){
			max = res;
			*index = i;
		}
	}
	return max;
}
