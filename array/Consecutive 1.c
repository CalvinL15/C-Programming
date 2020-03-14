#include <stdio.h>
#define MAXN 1000
 
int findLength (int array[][MAXN], int N, int r, int c, int dr, int dc){
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
 
int main () {
    int array[MAXN][MAXN];
    int N, r, c;
    int direction[4][2] = {{1,0}, {1,1}, {0,1}, {-1,1}};
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &array[i][j]);
    int res = -1, temp;
    for(int i = 0; i<N; i++){
        temp = findLength(array, N, i, 0, 0, 1);
        res = temp > res ? temp : res;   
        temp = findLength(array, N, i, 0, 1, 1);
        res = temp > res ? temp : res;     
        temp = findLength(array, N, 0, i, 1, 0);
        res = temp > res ? temp : res; 
        temp = findLength(array, N, 0, i, 1, 1);
        res = temp > res ? temp : res;       
        temp = findLength(array, N, N-1-i, 0, -1, 1);
        res = temp > res ? temp : res; 
        temp = findLength(array, N, 0, N-1-i, -1, 1);
        res = temp > res ? temp : res;         
    }
    printf("%d", res);
}
