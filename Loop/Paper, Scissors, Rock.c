#include <stdio.h>

int main(){
	int Xo, Yo;
	int a, b, c;
	int d, e, f;
	int saveresX;
	int saveresY;
	int zero = 0;
	int one = 1;
	int countround = 0;
	int trueround;
	scanf("%d %d %d %d", &Xo, &a, &b, &c);
	scanf("%d %d %d %d", &Yo, &d, &e, &f);
	scanf("%d", &trueround);
	int counting = 0;
	int t;
	for(t = 1; t<214483647; t++){
		countround++;
		if(t == 1){
			Xo = Xo;
			Yo = Yo;
		}
		else{
			Xo = (a*Xo + b) % c;
			Yo = (d*Yo + e) % f;
	 }
		saveresX = Xo % 3;
		saveresY = Yo % 3;
		
		if((saveresX == 0 && saveresY == 1) || (saveresX == 1 && saveresY == 2) || (saveresX == 2 && saveresY == 0)){
				printf("%d ", one);
				printf("%d\n", countround);
				countround = 0;
				counting++;
			}
		else if((saveresY == 0 && saveresX == 1) || (saveresY == 1 && saveresX == 2) || (saveresY == 2 && saveresX == 0)){
				printf("%d ", zero);
				printf("%d\n", countround);
				countround = 0;
				counting++;
			}
		if(counting == trueround)
			break;		
		}

		return 0;
}
