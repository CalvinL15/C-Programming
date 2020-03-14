#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int count = 0;
        int cur_count = 0;
        while(n){
            if(n&1 == 1){
                cur_count++;
                if(count < cur_count)
                    count = cur_count;
            }
            else cur_count = 0;
            n >>= 1;        
        }
        printf("%d\n", count);
    }
    return 0;
}
