//SMALLEST MULTIPLE

#include <stdio.h>

int main(){
	int mystery = 21;
	int flag = 0;
	while (flag == 0){
		if(mystery % 11 == 0 && mystery % 12 == 0 && mystery % 13 == 0 && mystery % 14 == 0 && mystery % 15 == 0 && mystery % 16 == 0 && mystery % 17 == 0 && mystery % 18 == 0 && mystery % 19 == 0 && mystery % 20 == 0)
			flag++;
		else mystery++;	
	}
	printf("%d", mystery);
	return 0;
}
