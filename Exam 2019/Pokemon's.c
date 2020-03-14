#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int k, sum = 0, water = 0, fire = 0, wind = 0,poke;
    int sechighest = 0, highest = 0;
    scanf("%d", &k);
    while(scanf("%d", &poke) != EOF){
        if(poke % 3 == 0)
            wind++;
        else if(poke % 3 == 1)
            fire++;
        else water++;
        if(poke >= highest){
            sechighest = highest;
            highest = poke;    
        }
        else if(poke > sechighest)
            sechighest = poke;
        if(wind >= k && fire >= k && water >= k){
            wind = 0, fire = 0, water = 0;
            sum += sechighest;
            sechighest = 0, highest = 0;  
        }
    }
   	if(wind+water+fire > 1)
    	sum += sechighest;
   	else if(wind+water+fire == 1)
    	sum += highest;        
   	printf("%d", sum);
	return 0;
}
