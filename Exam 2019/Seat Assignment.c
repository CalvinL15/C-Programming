#include <stdio.h>
#pragma GCC "03"
 
int main(){
    int n;
    int TSHR[1000][20][5] = {0};
    scanf("%d", &n);
    int curcardouble = 0, currowdouble = 0, curseatdouble = 0;
    int curcarsing = 0, currowsing = 0, curseatsing = 0;
    int r;
    int flag = 0;
    while(scanf("%d", &r) != EOF){
        flag = 0;
        if(r == 1){
            for(int i = curcarsing; i<n; i++){
                    if(i != curcarsing) currowsing = 0, curseatsing = 0;
                for(int j = currowsing; j<20; j++){
                        if(j != currowsing) curseatsing = 0;
                    for(int k = curseatsing; k<5; k++){
                        if(TSHR[i][j][k] == 0){
                            TSHR[i][j][k] = 1, flag = 1;
                            printf("%d %d %d\n", i+1, j+1, k+1);
                            curcarsing = i, currowsing = j, curseatsing = k;
                            i = n, j = 20, k = 5;
                        }
                    }
                }
            }
        }
        else if(r == 2){
            for(int i = curcardouble; i<n; i++){
                    if(i != curcardouble)
                        currowdouble = 0, curseatdouble = 0;
                for(int j = currowdouble; j<20; j++){
                        if(j != currowdouble)
                            curseatdouble = 0;
                    for(int k = curseatdouble; k<4; k++){
                        if(TSHR[i][j][k] == 0 && TSHR[i][j][k+1] == 0 && k!=2){
                            TSHR[i][j][k] = 1, TSHR[i][j][k+1] = 1, flag = 1;
                            printf("%d %d %d %d %d %d\n", i+1, j+1, k+1, i+1, j+1, k+2);
                            curcardouble = i, currowdouble = j, curseatdouble = k+1;
                            i = n, j = 20, k = 5;
                        }
                    }
                }
            }
            if(flag == 0){
                int ne = 2;
                while(ne > 0){
                    if(ne == 1) printf(" ");
                    for(int x = curcarsing; x<n; x++){
                        if(x != curcarsing) currowsing = 0, curseatsing = 0;
                        for(int y = currowsing; y<20; y++){
                            if(y != currowsing) curseatsing = 0;
                            for(int z = curseatsing; z<4; z++){
                                if(TSHR[x][y][z] == 0){
                                    TSHR[x][y][z] = 1;
                                    printf("%d %d %d", x+1, y+1, z+1);
                                    curcarsing = x, currowsing = y, curseatsing = z;
                                    x = 1000, y = 20, z = 5;
                                }
                            }   
                        }
                    }
                    ne--;
                    if(ne == 0) printf("\n");
                }
            }
        }
    }
 
    return 0;
}
