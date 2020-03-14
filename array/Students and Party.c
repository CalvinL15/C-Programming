#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define SIZE 32768
int friendshiplist[SIZE][256] = {0};
int checker[SIZE] = {0};
int main(){
    int N;
    int E;
    scanf("%d %d", &N, &E);
    int friendshiplist[N][256];
    for(int i = 0; i<N; i++)
        for(int j = 0; j<256; j++)
            friendshiplist[i][j] = INT_MAX;
    int checker[N];
  //  for(int i = 0; i<N; i++)
    //    checker[i] = 0;
    int vi, vj;
    for(int i = 0; i<E; i++){
        scanf("%d %d", &vi, &vj);
        int x = 0, y = 0;
        while(friendshiplist[vi][x] != INT_MAX)
            x++;
        friendshiplist[vi][x] = vj;
        while(friendshiplist[vj][y] != INT_MAX)
            y++;
        friendshiplist[vj][y] = vi;    
    }
    int meow;
    while(scanf("%d", &meow) != EOF){
        int count = 0;
        checker[meow] = 1;
        while(friendshiplist[meow][count] != INT_MAX){
            checker[friendshiplist[meow][count]] = 1;
            count++;
        }
    }
    int flag = 0;
    for(int i = 0; i<N; i++){
        if(checker[i] == 0){
            if(flag > 0)
                printf("\n");
            flag++;
            printf("%d", i);
        }
    }
    return 0;
}
