#include <stdlib.h>
#include <limits.h>
 
void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]){
    int count_A = 0, count_B = 0;
    int shadmap[N][M];
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            shadmap[i][j] = 0;
    shadmap[A_r][A_c] = 1, shadmap[B_r][B_c] = 2;
    int flagA = 0, flagB = 0, max = map[A_r][A_c], min = map[B_r][B_c], dirA, dirB;
    while(flagA == 0 || flagB == 0){
        if(flagA == 0){
            if(A_c < M-1 && map[A_r][A_c+1] > max)
                max = map[A_r][A_c+1], dirA = 0;
            if(A_c > 0 && map[A_r][A_c-1] > max)
                max = map[A_r][A_c-1], dirA = 1;    
            if(A_r < N-1 && map[A_r+1][A_c] > max)
                max = map[A_r+1][A_c], dirA = 2;
            if(A_r > 0 && map[A_r-1][A_c] > max)
                max = map[A_r-1][A_c], dirA = 3;
            if(A_r < N-1 && A_c < M-1 && map[A_r+1][A_c+1] > max)
                max = map[A_r+1][A_c+1], dirA = 4;
            if(A_r > 0 && A_c > 0 && map[A_r-1][A_c-1] > max)
                max = map[A_r-1][A_c-1], dirA = 5;
            if(A_r > 0 && A_c < M-1 && map[A_r-1][A_c+1] > max)
                max = map[A_r-1][A_c+1], dirA = 6;
            if(A_r < N-1 && A_c > 0 && map[A_r+1][A_c-1] > max)
                max = map[A_r+1][A_c-1], dirA = 7;
            if(max == map[A_r][A_c]) dirA = 8;        
            directionA[count_A] = dirA;
            if(dirA == 0) A_c++;
            else if(dirA == 1) A_c--;
            else if(dirA == 2) A_r++;
            else if(dirA == 3) A_r--;
            else if(dirA == 4) A_r++, A_c++;
            else if(dirA == 5) A_r--, A_c--;
            else if(dirA == 6) A_r--, A_c++;
            else if(dirA == 7) A_r++, A_c--;
            else flagA = -1, directionA[count_A] = -1;
            if(flagA != -1){
                if(shadmap[A_r][A_c] == 1)
                    flagA = -1, directionA[count_A] = -1;
                else if(shadmap[A_r][A_c] == 2)
                    flagA = -1, directionA[count_A+1] = -1;    
                else shadmap[A_r][A_c] = 1;
            }
        //    if(A_r == B_r && A_c == B_c) flagB = -1, directionB[count_B] = -1;
            count_A++;
        }
        if(flagB == 0){
            if(B_c < M-1 && map[B_r][B_c+1] < min)
                min = map[B_r][B_c+1], dirB = 0;
            if(B_c > 0 && map[B_r][B_c-1] < min)
                min = map[B_r][B_c-1], dirB = 1;    
            if(B_r < N-1 && map[B_r+1][B_c] < min)
                min = map[B_r+1][B_c], dirB = 2;
            if(B_r > 0 && map[B_r-1][B_c] < min)
                min = map[B_r-1][B_c], dirB = 3;
            if(B_r < N-1 && B_c < M-1 && map[B_r+1][B_c+1] < min)
                min = map[B_r+1][B_c+1], dirB = 4;
            if(B_r > 0 && B_c > 0 && map[B_r-1][B_c-1] < min)
                min = map[B_r-1][B_c-1], dirB = 5;
            if(B_r > 0 && B_c < M-1 && map[B_r-1][B_c+1] < min)
                min = map[B_r-1][B_c+1], dirB = 6;
            if(B_r < N-1 && B_c > 0 && map[B_r+1][B_c-1] < min)
                min = map[B_r+1][B_c-1], dirB = 7;
            if(min == map[B_r][B_c]) dirB = 8;        
            directionB[count_B] = dirB;
            if(dirB == 0) B_c++;
            else if(dirB == 1) B_c--;
            else if(dirB == 2) B_r++;
            else if(dirB == 3) B_r--;
            else if(dirB == 4) B_r++, B_c++;
            else if(dirB == 5) B_r--, B_c--;
            else if(dirB == 6) B_r--, B_c++;
            else if(dirB == 7) B_r++, B_c--;
            else flagB = -1, directionB[count_B] = -1;
            if(flagB != -1){
            if(shadmap[B_r][B_c] == 1)
                flagB = -1, directionB[count_B+1] = -1;
            else if(shadmap[B_r][B_c] == 2)
                flagB = -1, directionB[count_B] = -1;    
            else shadmap[B_r][B_c] = 2;
            }
            if(A_r == B_r && A_c == B_c) flagA = -1, directionA[count_A] = -1;
            count_B++;
        }
    //    max = -1, min = INT_MAX;                                        
    }
}
