#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    int M, N;
    int X1, Y1, E1, N1, F1;
    int X2, Y2, E2, N2, F2;
    int T = 0;
    int curmoveR1 = 0;
    int curmoveR2 = 0;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &M, &N, &X1, &Y1, &E1, &N1, &F1, &X2, &Y2, &E2, &N2, &F2);
//    int curxR1 = X1, curyR1 = Y1, curxR2 = X2, curxR2 = Y2;
    int east1 = E1, north1 = N1, east2 = E2, north2 = N2;
    int flag = 0;
    while((F1 > 0 || F2 > 0) && flag == 0){
        if(F1 > 0){
            if(curmoveR1 == 0){
                Y1++;
                north1--;
                if(Y1 >= N)
                    Y1 = 0;
                if(north1 == 0){
                    curmoveR1 = 1;
                    north1 = N1;
                }    
            }
            else if(curmoveR1 = 1){
                X1++;
                east1--;
                if(X1 >= M)
                    X1 = 0;
                if(east1 == 0){
                    curmoveR1 = 0;
                    east1 = E1;
                }    
            }
        }
        if(F2 > 0){
            if(curmoveR2 == 0){
                X2++;
                east2--;
                if(X2 >= M)
                    X2 = 0;
                if(east2 == 0){
                    curmoveR2 = 1;
                    east2 = E2;
                }    
            }
            else if(curmoveR2 == 1){
                Y2++;
                north2--;
                if(Y2 >= N)
                    Y2 = 0;
                if(north2 == 0){
                    curmoveR2 = 0;
                    north2 = N2;
                }    
            }
        }
        T++, F1--, F2--;
        if(X1 == X2 && Y1 == Y2){
            flag = 1;
            printf("robots explode at time %d", T);
        }
    }
    if(flag == 0)
        printf("robots will not explode");
}
