#include <stdio.h>
#include <limits.h>

int main(){
	int puzzle[5][5];
	int pos_x, pos_y;
	for(int i = 0; i<4; i++)
		for(int j = 0; j<4; j++){
			scanf("%d", &puzzle[i][j]);
			if(puzzle[i][j] == 0){
				pos_x = i;
				pos_y = j;
			}
		}
	for(int i = 0; i<5; i++){
		puzzle[4][i] = INT_MAX;
		puzzle[i][4] = INT_MAX;
	}	
	int flag = 0;
	int instructions;
	int countR = 0;
	while(flag == 0){
		scanf("%d ", &instructions);
		if(instructions == 0)
			flag++;
		else{
			if(puzzle[pos_x+1][pos_y] == instructions){
				puzzle[pos_x][pos_y] = instructions;
				pos_x++;
				puzzle[pos_x][pos_y] = 0;
			}
			else if(pos_x-1 >= 0 && puzzle[pos_x-1][pos_y] == instructions){
				puzzle[pos_x][pos_y] = instructions;
				pos_x--;
				puzzle[pos_x][pos_y] = 0;
			}
			else if(puzzle[pos_x][pos_y+1] == instructions){
				puzzle[pos_x][pos_y] = instructions;
				pos_y++;
				puzzle[pos_x][pos_y] = 0;
			}
			else if(pos_y-1 >= 0 && puzzle[pos_x][pos_y-1] == instructions){
				puzzle[pos_x][pos_y] = instructions;
				pos_y--;
				puzzle[pos_x][pos_y] = 0;
			}
		}
		int count = 1;
		for(int i = 0; i<4; i++)
			for(int j = 0; j<4; j++){
				if(puzzle[i][j] == count)
					count++;
				else break;		
			}
		if(count == 16){
			countR = count;
			break;	
		}
	}
	if(countR != 16){
		for(int i = 0; i<4; i++){
			for(int j = 0; j<4; j++){
				printf("%d", puzzle[i][j]);
				if(j != 3)
					printf(" ");
			}
			printf("\n");	
		}
		printf("0");
		
	}
	else {
		for(int i = 0; i<4; i++){
			for(int j = 0; j<4; j++){
				printf("%d", puzzle[i][j]);
				if(j != 3)
					printf(" ");
			}
			printf("\n");	
		}
		printf("1 %d", instructions);
	}
	return 0;		
}
