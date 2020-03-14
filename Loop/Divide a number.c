#include <stdio.h>
 
int main(){
    int N;
    int k;
    int meow = 0;
    int saving;
    int fml = 0;
    scanf("%d", &k);
    while(scanf("%d", &N) != EOF){
        meow = meow + N;
        saving = meow / k;
        meow = meow % k; 
        meow *= 10;
        if(saving != 0){
            fml = 1;
        }
        if(fml == 1)
        printf("%d\n", saving);
    }
    if(saving == 0 && fml != 1)
    printf("%d\n", saving);
 
    return 0;
}
