#include <stdio.h>
#include <limits.h>

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	int init_row, init_col, energy;
	scanf("%d %d %d", &init_row, &init_col, &energy);
	int map[N][M];
	for(int i = 0; i<N; i++)
		for(int j = 0; j<M; j++)
			map[i][j] = 0;
	map[init_row][init_col] = energy;
	int weight, row, col;
	int O; //number of stones;
	scanf("%d", &O);
	for(int i = 0; i<O; i++){
		scanf("%d %d %d", &row, &col, &weight);
		map[row][col] = weight;
	}
	int instructions;
	while(scanf("%d", &instructions) != EOF){
		if(instructions == 0){
			for(int i = 0; i<N; i++){
				for(int j = 0; j<M; j++){
					printf("%d", map[i][j]);
					if(j != M-1)
						printf(" ");	
				}
				printf("\n");
			}
		}
		else if(instructions == 2){
			if(init_row+1 < N){
				int temp_total_weight = 0;
				if(map[init_row+1][init_col] == 0){
					map[init_row+1][init_col] = energy;
					map[init_row][init_col] = 0;
					init_row++;
				}
				else{
					int flag = 0;
					for(int i = init_row+1; i<N; i++){
						if(map[i][init_col] != 0)
							temp_total_weight += map[i][init_col];
						else{
							flag = i;
							break;
						} 
						if(i == N-1)
							temp_total_weight = INT_MAX;	
					}
					if(temp_total_weight <= energy){
						energy -= temp_total_weight;
						map[init_row][init_col] = energy;
						for(int i = flag; i >= init_row+1; i--){
							map[i][init_col] = map[i-1][init_col];
						}
						map[init_row][init_col] = 0;
						init_row++;
					}
				}
			}
		}
		else if(instructions == 1){
			if(init_col+1 < M){
				int temp_total_weight = 0;
				if(map[init_row][init_col+1] == 0){
					map[init_row][init_col+1] = energy;
					map[init_row][init_col] = 0;
					init_col++;
				}
				else{
					int flag = 0;
					for(int i = init_col+1; i<M; i++){
						if(map[init_row][i] != 0)
							temp_total_weight += map[init_row][i];
						else{
							flag = i;
							break;
						} 
						if(i == M-1)
							temp_total_weight = INT_MAX;	
					}
					if(temp_total_weight <= energy){
						energy -= temp_total_weight;
						map[init_row][init_col] = energy;
						for(int i = flag; i >= init_col+1; i--){
							map[init_row][i] = map[init_row][i-1];
						}
						map[init_row][init_col] = 0;
						init_col++;
					}	
				}
			}	
		}
		else if(instructions == 4){
			if(init_row-1 >= 0){
				int temp_total_weight = 0;
				if(map[init_row-1][init_col] == 0){
					map[init_row-1][init_col] = energy;
					map[init_row][init_col] = 0;
					init_row--;
				}
				else{
					int flag = 0;
					for(int i = init_row-1; i>=0; i--){
						if(map[i][init_col] != 0)
							temp_total_weight += map[i][init_col];
						else{
							flag = i;
							break;
						} 
						if(i == 0)
							temp_total_weight = INT_MAX;	
					}
					if(temp_total_weight <= energy){
						energy -= temp_total_weight;
						map[init_row][init_col] = energy;
						for(int i = flag; i <= init_row-1; i++){
							map[i][init_col] = map[i+1][init_col];
						}
						map[init_row][init_col] = 0;
						init_row--;
					}
				}
			}	
		}
		else if(instructions == 3){
			if(init_col-1 >= 0){
				int temp_total_weight = 0;
				if(map[init_row][init_col-1] == 0){
					map[init_row][init_col-1] = energy;
					map[init_row][init_col] = 0;
					init_col--;
				}
				else{
					int flag = 0;
					for(int i = init_col-1; i>=0; i--){
						if(map[init_row][i] != 0)
							temp_total_weight += map[init_row][i];
						else{
							flag = i;
							break;
						} 
						if(i == 0)
							temp_total_weight = INT_MAX;	
					}
					if(temp_total_weight <= energy){
						energy -= temp_total_weight;
						map[init_row][init_col] = energy;
						for(int i = flag; i <= init_col-1; i++){
							map[init_row][i] = map[init_row][i+1];
						}
						map[init_row][init_col] = 0;
						init_col--;
					}	
				}
			}	
		}				
	}
}
