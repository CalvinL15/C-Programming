#include <stdio.h>
#include "findLength.h"
#define MAXN 256
 
int main () {
    int array[MAXN][MAXN];
    int N, r, c;
    int direction[4][2] = {{1,0}, {1,1}, {0,1}, {-1,1}};
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &array[i][j]);
    scanf("%d%d", &r, &c);
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
