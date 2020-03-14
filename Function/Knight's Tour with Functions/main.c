#include <stdio.h>
 
int visited[100][100] = {0};
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int stateknight[m];
    int stepcount[m];
    int F = 0;
    for(int i = 0; i<m; i++)
        stateknight[i] = 0, stepcount[i] = 0;
    int r[m], c[m];    
    for(int i = 0; i<m; i++)
        scanf("%d %d", &r[i], &c[i]);
    while(F<m){
        for(int i = 0; i<m; i++){
            if(stateknight[i] == 1)
                continue;
            else{
                int x = nextMove(r[i], c[i], n, visited);
                visited[r[i]][c[i]] = (i+1)*10000+stepcount[i];
                if(x == -1){
                    stateknight[i] = 1, F++;
                    continue;    
                }
                else if(x == 0)
                    r[i] = r[i]-2, c[i] = c[i]+1;
                else if(x == 1)
                    r[i] = r[i]-1, c[i] = c[i]+2;
                else if(x == 2)
                    r[i] = r[i]+1, c[i] = c[i]+2;    
                else if(x == 3)
                    r[i] = r[i]+2, c[i] = c[i]+1;
                else if(x == 4)
                    r[i] = r[i]+2, c[i] = c[i]-1;
                else if(x == 5)
                    r[i] = r[i]+1, c[i] = c[i]-2;
                else if(x == 6)
                    r[i] = r[i]-1, c[i] = c[i]-2;
                else r[i] = r[i]-2, c[i] = c[i]-1;
                stepcount[i]++;
 
            }    
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%d", visited[i][j]);
            if(j != n-1)
                printf(" ");
        }
        if(i != n-1)
            printf("\n");
    }
    return 0;    
}
