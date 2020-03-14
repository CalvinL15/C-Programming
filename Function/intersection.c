#include <stdio.h>
#include "intersection.h"
 
void intersection(int map[100][100], int result[4]) {
    int city[102][102] = {0};
    int i, j;
      for(i = 0; i<4; i++)
      result[i] = 0;
    for(i = 1; i < 101; i++){
        for(j = 1; j < 101; j++){
            city[i][j] = map[i-1][j-1];
        }
    }       
    for(i = 1; i<101; i++){
        for(j = 1; j<101; j++){
                if(city[i][j] == 0)
                    continue;
                int pts = 0;   
                 if(city[i][j+1] == 1)
                      pts++;
                 if(city[i+1][j] == 1)
                     pts++;
                if(city[i][j-1] == 1)
                     pts++;
                if(city[i-1][j] == 1)
                     pts++;  
                if(pts == 4)
                    result[0]++;
 
                if(pts == 3)
                    result[1]++;
 
                if(pts == 2){
                    if(city[i+1][j] != city[i-1][j]){   
                    result[2]++;
                    }
                }
                if(pts == 1)
                    result[3]++;
 
        }
    }
}
