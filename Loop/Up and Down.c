#include <stdio.h>
int main (){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("%d\n", i);
    }
    for(int j = n - 1; j >= 1; j--){
        printf("%d\n", j);
    }
    return 0;
}
