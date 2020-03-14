#include <stdio.h>
int res = 0;

void ways(int matrix[12][12], int r, int c, int cur_r, int cur_c){
	if(cur_r == r-1 && cur_c == c-1){
		res++;
		return;
	}
	if(matrix[cur_r][cur_c] == 0)
		return;
	ways(matrix, r, c, cur_r+1, cur_c);
	ways(matrix, r, c, cur_r, cur_c+1);
}

int main(){
	int matrix[12][12];
	int r, c;
	scanf("%d %d", &r, &c);
	for(int i = r-1; i>=0; i--)
		for(int j = 0; j<c; j++)
			scanf("%d", &matrix[i][j]);
	ways(matrix, r, c, 0, 0);		
	printf("%d", res);		
}
