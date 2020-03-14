#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int area[N+1][M+1];
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            area[i][j] = 0;
    int SX, SY, EX, EY;
    scanf("%d %d %d %d", &SX, &SY, &EX, &EY);
    int X_dist = abs(SX-EX);
    int Y_dist = abs(SY-EY);
    int size;
    if(X_dist > Y_dist)
        size = X_dist+1;
    else size = Y_dist+1;
    int state_x[size+1];
    int state_y[size+1];
    state_x[0] = SX, state_y[0] = SY;
    state_x[size-1] = EX, state_y[size-1] = EY;
    if(X_dist == 0){
        int pos = SY;
        int flag;
        if(SY > EY) flag = 1;
        else flag = 0; 
        for(int i = 1; i<size-1; i++){
            state_x[i] = SX;
            if(flag == 1)
                pos--;
            else pos++;
            state_y[i] = pos;
        }
    }
    else{
        int pos = SX;
        int flag;
        if(SX > EX) flag = 1;
        else flag = 0;
        for(int i = 1; i<size-1; i++){
            state_y[i] = SY;
            if(flag == 1)
                pos--;
            else pos++;
            state_x[i] = pos;
        }
    }
    int Q;
    scanf("%d", &Q);
    int D;
    for(int i = 0; i<Q; i++){
        scanf("%d", &D);
        if(D == 0){
            int meowman = 0;
            for(int i = 1; i< size-1; i++)
                if(state_x[i] == state_x[0]+1 && state_y[i] == state_y[0])
                    meowman = 1;
            if(state_x[0] == N-1 || meowman == 1)
                break;
            else{
                for(int i = size-1; i >= 1; i--){
                    state_x[i] = state_x[i-1];
                    state_y[i] = state_y[i-1];
                }
                state_x[0] += 1;        
            }    
        }
        else if(D == 1){
            int meowman = 0;
            for(int i = 1; i< size-1; i++)
                if(state_x[i] == state_x[0]-1 && state_y[i] == state_y[0])
                    meowman = 1;
            if(state_x[0] == 0 || meowman == 1)
                break;
            else{
                for(int i = size-1; i>=1; i--){
                    state_x[i] = state_x[i-1];
                    state_y[i] = state_y[i-1];
                }
                state_x[0] -= 1;    
            }    
        }
        else if(D == 2){
            int meowman = 0;
            for(int i = 1; i< size-1; i++)
                if(state_y[i] == state_y[0]+1 && state_x[0] == state_x[i])
                    meowman = 1;
            if(state_y[0] == M-1 || meowman == 1)
                break;
            else{
                for(int i = size-1; i>=1; i--){
                    state_x[i] = state_x[i-1];
                    state_y[i] = state_y[i-1];    
                }
                state_y[0] += 1;    
            }
        }
        else if(D == 3){
            int meowman = 0;
            for(int i = 1; i< size-1; i++)
                if(state_y[i] == state_y[0]-1 && state_x[0] == state_x[i])
                    meowman = 1;
            if(state_y[0] == 0 || meowman == 1)
                break;
            else{
                for(int i = size-1; i>=1; i--){
                    state_x[i] = state_x[i-1];
                    state_y[i] = state_y[i-1];    
                }
                state_y[0] -= 1;    
            }
        }
    }
    for(int i = 0; i<size; i++){
        area[state_x[i]][state_y[i]] = 1;
    }    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++){
            if(j == 0 && i != 0)
                printf("\n");
            printf("%d", area[i][j]);
        }
}
