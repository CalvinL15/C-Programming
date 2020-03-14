#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(){
    int n;
    scanf("%d", &n);
    double matrix[n][n];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%lf", &matrix[i][j]);
    double vector[n];
    for(int i = 0; i<n; i++)
        scanf("%lf", &vector[i]);
    double result[n];
    result[n-1] = vector[n-1]/matrix[n-1][n-1];
    for(int i = n-2; i>=0; i--){
        double sum = 0.0;
        for(int j = n-1; j>i; j--)
            sum += result[j]*matrix[i][j];
        result[i] = (vector[i]-sum)/matrix[i][i];    
    }
    for(int i = 0; i<n; i++){
        printf("%f", result[i]);
        if(i != n-1)
            printf("\n");
    }
    return 0;                
}
