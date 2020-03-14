#include <stdio.h>

int main(){
	int money;
	int countfor1000 = 0;
	int countfor500 = 0, countfor100 = 0, countfor50 = 0, countfor10 = 0, countfor5 = 0, countfor1 = 0,
	while(scanf("%d", &money) != EOF){
		MEOW:
		if(money >= 1000){
			money -= 1000;
			countfor1000++;
			goto MEOW;
		}
		if(money < 1000 && money >= 500){
			money -= 500;
			countfor500++;
			goto MEOW;
		}
		if(money < 500 && money >= 100){
			money -= 100;
			countfor100++;
			goto MEOW;
		}
		if(money < 100 && money >= 50){
			money -= 50;
			countfor50++;
			goto MEOW;
		}
		if(money < 50 && money >= 10){	
			money -= 10;
			countfor10++;
			goto MEOW;
		}
		if(money < 10 && money >= 5){
			money -= 5;
			countfor5++;	
			goto MEOW;
		}
		if(money < 5 && money >= 1){
			money -= 1;
			countfor1++;
			goto MEOW;	
		}
	}
	printf("%d %d %d %d %d %d %d", countfor1000, countfor500, countfor100, countfor50, countfor10, countfor5, countfor1);
	return 0;
}
