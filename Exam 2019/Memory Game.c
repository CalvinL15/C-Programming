#include <stdio.h>
 
int main(){
    int N;
    scanf("%d", &N);
    int num, occurence[101] = {0}, firstocc[101] = {0};
    for(int i = 0; i<N; i++){
        scanf("%d", &num);
        occurence[num]++;
        if(i != 0)
            printf("\n");
        printf("%d", i);
        if(occurence[num] == 2){
            printf(" %d %d", firstocc[num], num);    
            occurence[num] = 0;    
        }
        else firstocc[num] = i;
    }
    return 0;
}
