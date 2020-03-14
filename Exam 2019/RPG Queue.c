#include <stdio.h>
 
int main(){
    int countDPS = 0, countHealer = 0, countTank = 0;
	int cDPS = 0, cHealer = 0, cTank = 0;
	int x = 0, y = 0, z = 0;
    int DPS[5000] = {0}, Healer[5000] = {0}, Tank[5000] = {0};
    int id;
    while(scanf("%d", &id) != EOF){
        if(id % 3 == 0){
            DPS[countDPS%5000] = id;
            countDPS++;
            cDPS++;    
        }
        else if(id % 3 == 1){
            Healer[countHealer%5000] = id;
            countHealer++;
            cHealer++;
        }
        else{
            Tank[countTank%5000] = id;
            countTank++;
            cTank++;
        }
        if(cDPS >= 3 && cHealer >= 1 && cTank >= 1){
            printf("%d %d %d %d %d\n", DPS[x%5000], DPS[(x+1)%5000], DPS[(x+2)%5000], Healer[y%5000], Tank[z%5000]);
            cDPS -= 3, cHealer -= 1, cTank -= 1;
            x+=3, y+=1, z+=1;
        } 
    }
    return 0;        
}
