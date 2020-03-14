#include <stdio.h>
#include <limits.h>
 
struct knights{
    int row;
    int col;
    int stepcount;
    int flag;
};
 
int area[105][105];
int countP(int row, int col, int n){
    int p = 0;
    if(area[row][col] != 0)
        return INT_MAX;
    if(row < 0 || row > n-1 || col < 0 || col > n-1)
        return INT_MAX;
    if(area[row-2][col+1] == 0 && row-2 >= 0 && col+1 < n)
        p++;
    if(area[row-1][col+2] == 0 && row-1 >= 0 && col+2 < n)
        p++;
    if(area[row+1][col+2] == 0 && row+1 < n && col+2 < n)
        p++;
    if(area[row+2][col+1] == 0 && row+2 < n && col+1 < n)
        p++;
    if(area[row-2][col-1] == 0 && row-2 >= 0 && col-1 >= 0)
        p++;
    if(area[row-1][col-2] == 0 && row-1 >= 0 && col-2 >= 0)
        p++;
    if(area[row+1][col-2] == 0 && row+1 < n && col-2 >= 0)
        p++;
    if(area[row+2][col-1] == 0 && row+2 < n && col-1 >= 0)
        p++;
    return p;    
 
}
 
int main(){
    int m, n;
    scanf("%d %d", &n, &m);
    struct knights arr[m+1];
    for(int i = 1; i<= m; i++){
        arr[i].stepcount = 0;
        arr[i].flag = 0;
    }
//    int area[n+5][n+5];
    for(int i = 0; i<n+5; i++)
        for(int j = 0; j<n+5; j++)
            area[i][j] = INT_MAX;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            area[i][j] = 0;        
    int row, col;    
    for(int i = 1; i<=m; i++){
        scanf("%d %d", &row, &col);
        area[row][col] = 10000*i;
        arr[i].row = row;
        arr[i].col = col;
    }
    int flagger = 0;
    int p = INT_MAX;
    int penanda = 0;
    while(flagger < m){
        for(int i = 1; i<=m; i++){
            if(arr[i].flag == 1)
                continue;
            int temp = 0;
            temp = countP(arr[i].row-2, arr[i].col+1, n); //1
            if(temp < p)
                p = temp, penanda = 1;    
            temp = countP(arr[i].row-1, arr[i].col+2, n); //2    
            if(temp < p)
                p = temp, penanda = 2;    
            temp = countP(arr[i].row+1, arr[i].col+2, n); //3
            if(temp < p)
                p = temp, penanda = 3;
            temp = countP(arr[i].row+2, arr[i].col+1, n); //4
            if(temp < p)
                p = temp, penanda = 4;
            temp = countP(arr[i].row+2, arr[i].col-1, n); //5
            if(temp < p)
                p = temp, penanda = 8;
            temp = countP(arr[i].row+1, arr[i].col-2, n); //6
            if(temp < p)
                p = temp, penanda = 7;
            temp = countP(arr[i].row-1, arr[i].col-2, n); //7
            if(temp < p)
                p = temp, penanda = 6;                        
            temp = countP(arr[i].row-2, arr[i].col-1, n); //8
            if(temp < p)
                p = temp, penanda = 5;     
            if(penanda == 0)
                flagger++, arr[i].flag = 1;
            else if(penanda == 1){
                arr[i].row -= 2;
                arr[i].col += 1;
                arr[i].stepcount++;
                area[arr[i].row][arr[i].col] = 10000*i + arr[i].stepcount;
            }
            else if(penanda == 2){
                arr[i].row -= 1, arr[i].col += 2;
                arr[i].stepcount++;
                area[arr[i].row][arr[i].col] = 10000*i + arr[i].stepcount;
            }
            else if(penanda == 3){
                arr[i].row    += 1, arr[i].col += 2;
                arr[i].stepcount++;
                area[arr[i].row][arr[i].col] = 10000*i + arr[i].stepcount;
            } 
            else if(penanda == 4){ 
                arr[i].row += 2, arr[i].col += 1;
                arr[i].stepcount++;
                area[arr[i].row][arr[i].col] = 10000*i + arr[i].stepcount;
            } 
            else if(penanda == 5){ 
                arr[i].row -= 2, arr[i].col -= 1;
                arr[i].stepcount++;
                area[arr[i].row][arr[i].col] = 10000*i + arr[i].stepcount;
            } 
            else if(penanda == 6){ 
                arr[i].row -= 1, arr[i].col -= 2;
                arr[i].stepcount++;
                area[arr[i].row][arr[i].col] = 10000*i + arr[i].stepcount;
            } 
            else if(penanda == 7){ 
                arr[i].row += 1, arr[i].col -= 2;
                arr[i].stepcount++;
                area[arr[i].row][arr[i].col] = 10000*i + arr[i].stepcount;
            } 
            else if(penanda == 8){ 
                arr[i].row += 2, arr[i].col -= 1;
                arr[i].stepcount++;
                area[arr[i].row][arr[i].col] = 10000*i + arr[i].stepcount;
            }                
        //    penanda = 0;
        //    printf("%d ", penanda);    
            penanda = 0, p = INT_MAX;                    
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%d", area[i][j]);
            if(j != n-1)
                printf(" ");
        }
        printf("\n");
    }
}
