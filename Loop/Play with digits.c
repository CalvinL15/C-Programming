#include <stdio.h>
 
int main(){
    int N;
    int digits = 0;
    int sum = 0;
    int oczero = 0;
    int evenorodd = 0;
    while(scanf("%d", &N) != EOF){
        digits++;
        if(digits % 2 == 1)
            sum += N;
        else sum -= N;
        if(N == 0) oczero++;
        evenorodd = N;
    }
    if(sum%11 == 0) sum = 1;
      else sum = 0;
    if(evenorodd % 2 == 0) evenorodd = 1;
    else evenorodd = 0;
    printf("%d\n%d\n%d\n%d", digits, evenorodd, oczero, sum);
    return 0;
}
