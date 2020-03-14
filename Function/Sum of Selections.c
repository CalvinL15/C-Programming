#include <stdio.h>
 
int factorial(int n){
    int sum = 1;
    for(int i = n; i > 0; i--){
        sum = sum * i;
    }
    return sum;
 
}
int main(){
    int n;
    int m;
    int summation = 0;
    scanf("%d %d", &n, &m);
    int i;
    for(i = 0; i <= m; i++){
        summation += (factorial(n)) / (factorial(i) * factorial(n-i));
    }
    printf("%d", summation);
    return 0;
}