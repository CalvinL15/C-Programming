#include <stdio.h>
void game_of_cell(int grid[50][50],int outcome[50][50],int N){
    int i, j, k;
    int quantifier = 0;
    
    for(k = 0; k<N; k++){
        	
        for(i = 0; i<50; i++){
            for(j = 0; j<50; j++){
                if (grid[i][j] == 0){
                	outcome[i][j] = 0; 
                    if(grid[i+1][j] == 2 && i != 49)
                        quantifier += 1;
                    if(grid[i-1][j] == 2 && i != 0)
                        quantifier += 1;
                    if(grid[i][j+1] == 2 && j != 49)
                        quantifier += 1;
                    if(grid[i][j-1] == 2 && j != 0)
                        quantifier += 1;
                    if(grid[i+1][j+1] == 2 && i != 49 && j != 49)
						quantifier += 1;
					if(grid[i-1][j+1] == 2 && i != 0 && j != 49)
						quantifier += 1;	
					if(grid[i+1][j-1] == 2 && i != 49 && j != 0)
						quantifier += 1;	    
					if(grid[i-1][j-1] == 2 && i != 0 && j != 0)
						quantifier += 1;	
                    if(quantifier == 3)
                        outcome[i][j] = 2;  
                        
                              
                }
                else if (grid[i][j] == 1){
                    outcome[i][j] = 1;
					if(grid[i+1][j] == 2 && i != 49)
                        quantifier += 1;
                    if(grid[i-1][j] == 2 && i != 0)
                        quantifier += 1;
                    if(grid[i][j+1] == 2 && j != 49)
                        quantifier += 1;
                    if(grid[i][j-1] == 2 && j != 0)
                        quantifier += 1;
                    if(grid[i+1][j+1] == 2 && i != 49 && j != 49)
						quantifier += 1;
					if(grid[i-1][j+1] == 2 && i != 0 && j != 49)
						quantifier += 1;	
					if(grid[i+1][j-1] == 2 && i != 49 && j != 0)
						quantifier += 1;	    
					if(grid[i-1][j-1] == 2 && i != 0 && j != 0)
						quantifier += 1;	
                    if(quantifier == 2)
                        outcome[i][j] = 2;   
                   
                }
                else{
                	outcome[i][j] = 2;
                    if(grid[i+1][j] == 2 && i != 49)
                        quantifier += 1;
                    if(grid[i-1][j] == 2 && i != 0)
                        quantifier += 1;
                    if(grid[i][j+1] == 2 && j != 49)
                        quantifier += 1;
                    if(grid[i][j-1] == 2 && j != 0)
                        quantifier += 1;
                    if(grid[i+1][j+1] == 2 && i != 49 && j != 49)
						quantifier += 1;
					if(grid[i-1][j+1] == 2 && i != 0 && j != 49)
						quantifier += 1;	
					if(grid[i+1][j-1] == 2 && i != 49 && j != 0)
						quantifier += 1;	    
					if(grid[i-1][j-1] == 2 && i != 0 && j != 0)
						quantifier += 1;	
					if(quantifier < 2)
                        outcome[i][j] = 0;
                    if(quantifier > 3)
                        outcome[i][j] = 1;
                           
                }
                quantifier = 0;
            }
        }
				for(i = 0; i<50; i++){
            		for(j = 0; j<50; j++){
            			grid[i][j] = outcome[i][j];
            		}
				}
				
        	}
                //return outcome[i][j];
        }
  

