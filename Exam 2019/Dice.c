#include <stdio.h>
 
int dice[1001][1001];
int main(){
    int R, C;
    scanf("%d %d", &R, &C);
    int dice[R+1][C+1];
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
            scanf("%d", &dice[i][j]);
    int ans = 0;
    int r1, r2, r3, r4;
    for(int i = 1; i < R-1; i++){
        for(int j = 0; j+3<C; j++){
            int flag[7] = {0};
            int f2 = 0;
            flag[dice[i][j]] += 1, flag[dice[i][j+1]] += 1, flag[dice[i][j+2]] += 1, flag[dice[i][j+3]] += 1;
            for(int k = 1; k<7; k++){
                if(flag[k] > 1){
                    f2 = 1;
                    break;    
                }
            }
            if(f2 == 1) continue;
            r1 = dice[i][j], r2 = dice[i][j+1];
            r3 = dice[i][j+2], r4 = dice[i][j+3];
            if(r1 + r3 != 7 || r2 + r4 != 7)
                continue;
            for(int x = j; x<=j+3; x++){
                for(int y = j; y<=j+3; y++){
                    if(dice[i+1][x] + dice[i-1][y] == 7){
                        if(flag[dice[i+1][x]] == 0 && flag[dice[i-1][y]] == 0)
                            ans++;
                    }
                }
            } 
       
        }
    }
    printf("%d", ans);
    return 0;
}
