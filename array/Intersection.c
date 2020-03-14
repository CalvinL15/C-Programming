#include <stdio.h>
 
int main(){
    int intersection = 0;
    int Tjunction = 0;
    int turn = 0;
    int deadend = 0;
    int city[102][102] = {0};
    int n;
    int i, j;
    scanf("%d", &n);
    for(i = 1; i<=n; i++){
        for(j = 1; j<=n; j++){
            scanf("%d", &city[i][j]);
        }
    }
 
 
    for(i = 1; i<=n; i++){
        for(j = 1; j<=n; j++){
            int pts = 0;
            if(city[i][j] == 0) continue;
            if(city[i][j+1] == 1)
                pts++;
            if(city[i+1][j] == 1)
                pts++;
            if(city[i][j-1] == 1)
                pts++;
            if(city[i-1][j] == 1)
                pts++;   
            if(pts == 4)
				intersection++;
            if(pts == 3)
				Tjunction++;
            if(pts == 2){
				if(((city[i+1][j] == 1) && (city[i][j+1] == 1)) || ((city[i+1][j] == 1) && (city[i][j-1] == 1)) || ((city[i-1][j] == 1) && (city[i][j+1] == 1)) || ((city[i-1][j] == 1) && (city[i][j-1] == 1))){    
                    turn++;
                }
            }
            if(pts == 1)
				deadend++;
            }
        }
    printf("%d\n%d\n%d\n%d", intersection, Tjunction, turn, deadend);
    return 0;
}
