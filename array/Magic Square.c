#include <stdio.h>
 
int main(){
    int N;
    int k;
    int x, y;
    scanf("%d %d %d %d", &N, &k, &x, &y);
    int matrix[N][N];
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            matrix[i][j] = 0;
    matrix[x][y] = k;
    int count = 0;
    int nextposx, nextposy;
    if(k == 1){
        while(count < N*N-1){
            if(x-1 == -1)
                nextposx = N-1;
            else nextposx = x-1;    
            if(y+1 == N)
                nextposy = 0;
            else nextposy = y+1;
            if(matrix[nextposx][nextposy] != 0){
                if(x+1 == N)
                    nextposx = 0, nextposy = y;
                else nextposx = x+1, nextposy = y;
            }
            count++;
            matrix[nextposx][nextposy] = count+1;     
            x = nextposx, y = nextposy;    
        }
    }
    else{
        count = 0;
        int realx = x;
        int realy = y;
        for(int i = 0; i<=k-1; i++){
            if(x+1 == N)
                nextposx = 0;
            else nextposx = x+1;
            if(y-1 == -1)
                nextposy = N-1;
            else nextposy = y-1;
            count++;
            matrix[nextposx][nextposy] = k-count;
            x = nextposx, y = nextposy;
        }
        int count = k;
        matrix[realx][realy] = k;
        while(count < N*N){
            if(realx-1 == -1)
                nextposx = N-1;
            else nextposx = realx-1;    
            if(realy+1 == N)
                nextposy = 0;
            else nextposy = realy+1;
            if(matrix[nextposx][nextposy] != 0)
                if(realx+1 != N)
                    nextposx = realx+1, nextposy = realy;
                else nextposx = 0, nextposy = realy;        
            count++;
            matrix[nextposx][nextposy] = count;     
            realx = nextposx, realy = nextposy;    
        }
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            printf("%d", matrix[i][j]);
            if(j != N-1)
                printf(" ");    
        }
        printf("\n");
    }
}
