#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    int W, D;
    scanf("%d %d", &W, &D);
    int room[D][W];
    for(int i = 0; i<D; i++)
        for(int j = 0; j<W; j++)
            scanf("%d", &room[i][j]);
//    int startingx = 0, startingy = D-1;
    for(int i = 0; i<W; i++){
        int row = D-1, column = i;
        int move = 0;
        int flag = 0;
        while(flag == 0){
            if(move == 0){
                if(room[row][column] == 0){
                    row--;
                    if(row < 0){
                        printf("%d\n", W+D-1+W-column);
                        flag = 1;
                    }            
                }
                else{
                    move = 1;
                    column++;
                    if(column > W-1){
                        printf("%d\n", W-1+D-row);
                        flag = 1;
                    }    
                }    
            }
            else if(move == 1){
                if(room[row][column] == 0){
                    column++;
                    if(column > W-1){
                        printf("%d\n", W-1+D-row);
                        flag = 1;
                    }
                }
                else {
                    move = 0;
                    row--;
                    if(row < 0){
                        printf("%d\n", W+D-1+W-column);
                        flag = 1;
                    }    
                }    
            }    
        } 
    }
    for(int i = D-1; i>=0; i--){
        int row = i, column = W-1;
        int move = 0, flag = 0;
        while(flag == 0){
            if(move == 0){
                if(room[row][column] == 0){
                    column--;
                    if(column < 0){
                        printf("%d\n", 2*(W+D)-D+row);
                        flag = 1;
                    }
                }
                else{
                    move = 1;
                    row++;
                    if(row > D-1){
                        printf("%d\n", column);
                        flag = 1;
                    }
                }
            }
            else if (move == 1){
                if(room[row][column] == 0){
                    row++;
                    if(row > D-1){
                        printf("%d\n", column);
                        flag = 1;
                    }
                }
                else{
                    move = 0;
                        column--;
                    if(column < 0){
                        printf("%d\n", 2*(W+D)-D+row);
                        flag = 1;
                    }
                }
            }
        }    
    }
    for(int i = W-1; i>=0; i--){
        int move = 0, flag = 0;
        int row = 0, column = i;
        while(flag == 0){
            if(move == 0){
                if(room[row][column] == 0){
                    row++;
                    if(row > D-1){
                        printf("%d\n", column);
                        flag = 1;
                    }
                }
                else{
                    move = 1;
                    column--;
                    if(column < 0){
                        printf("%d\n", 2*(W+D)-D+row);
                        flag = 1;
                    }
                }
            }
            else if(move == 1){
                if(room[row][column] == 0){
                    column--;
                    if(column < 0){
                        printf("%d\n", 2*(W+D)-D+row);
                        flag = 1;
                    }
                }
                else{
                    move = 0;
                    row++;
                    if(row > D-1){
                        printf("%d\n", column);
                        flag = 1;
                    }
                }
            }
        }
    }
    for(int i = 0; i<D; i++){
        int move = 0, flag = 0;
        int row = i, column = 0;
        while(flag == 0){
            if(move == 0){
                if(room[row][column] == 0){
                    column++;
                    if(column > W-1){
                        printf("%d\n", W-1+D-row);
                        flag = 1;
                    }
                }
                else {
                    move = 1;
                    row--;
                    if(row < 0){
                        printf("%d\n", W+D-1+W-column);
                        flag = 1;
                    }    
                }    
            }
            else if(move == 1){
                if(room[row][column] == 0){
                    row--;
                    if(row < 0){
                        printf("%d\n", W+D-1+W-column);
                        flag = 1;
                    }            
                }
                else{
                    move = 0;
                    column++;
                    if(column > W-1){
                        printf("%d\n", W-1+D-row);
                        flag = 1;
                    }    
                }    
            }
        }
    }        
}
