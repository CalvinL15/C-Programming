#include "findLength.h"
 
int findLength (int array[][256], int N, int r, int c, int dr, int dc){
    int max = -1;
    if(dr == 1 && dc == 0){
        int cons = 0;
        while(r <= N-1){
            if(array[r][c] == 1)
                cons++;
            else cons = 0;
            if(max < cons)
                max = cons;
            r++;        
        }
    }
    else if(dr == 1 && dc == 1){
        int cons = 0;
        while(r <= N-1 && c <= N-1){
            if(array[r][c] == 1)
                cons++;
            else cons = 0;
            if(max < cons)
                max = cons;
            r++, c++;        
        }
    }
    else if(dr == 0 && dc == 1){
        int cons = 0;
        while(c <= N-1){
            if(array[r][c] == 1)
                cons++;
            else cons = 0;
            if(max < cons)
                max = cons;
            c++;        
        }
    }
    else if(dr == -1 && dc == 1){
        int cons = 0;
        while(r >= 0 && c <= N-1){
            if(array[r][c] == 1)
                cons++;
            else cons = 0;
            if(max < cons)
                max = cons;
            r--, c++;        
        }
    }
    return max;
}
