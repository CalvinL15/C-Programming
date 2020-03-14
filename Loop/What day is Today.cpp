#include <stdio.h>

int main(){
	int year;
	int control = 0;
	int whatday;
	int whatdate, whatmonth;
	int n;
	int m; 
	int dayFebruary;
	int dayinmonths[m] = {31, dayFebruary, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};   
	scanf("%d%d", &year, whatday);
	int index;
	for(int index = 1; index <= n; index++){
		scanf("%d", &n);
		scanf("%d%d", &whatdate, &whatmonth);
		if(year % 4 == 0)
			control = 1; 
		if(control == 1)
			dayFebruary = 29;
		else dayFebruary = 28;
	}
	printf("%d", &whatday);

	return 0;
} 
