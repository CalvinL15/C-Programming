#include <stdio.h>

int main(){
	int year;
	int control = 0;
	int whatday;
	int whatdate, whatmonth;
	int n;
	int m; 
	int dayinmonths[] = {0, 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int countingday[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	int index;
	int base;
	while (scanf("%d %d", &year, &base) == 2) {
    	scanf("%d", &n);
    	int sum, sumcontrol, leap;
		for(index = 1; index <= n; index++){
			scanf("%d%d", &whatmonth, &whatdate);
			if((year % 4 == 0 && year % 100 != 0) || year%400 == 0)
				control = 1; 
			else control = 0;	
			if (whatmonth < 1 || whatmonth > 12){
				printf("%d\n", -1);
				continue;
			}
			if (whatdate < 1 || (whatdate > 31) || (whatdate > 30 && (whatmonth == 4 || whatmonth == 6 || whatmonth == 9 || whatmonth == 11)) || 
			(whatdate > 28 && whatmonth == 2 && control == 0) || (whatdate > 29 && whatmonth == 2 && control == 1)){
				printf("%d\n", -2);		
				continue;
			}
			leap = year/4 - year/100 + year/400;
			if((year % 4 == 0 && year % 100 != 0) || year%400 == 0 && (whatmonth > 3))
				sum = year * 365 + leap + countingday[whatmonth] + 1 + whatdate;
			else sum = year * 365 + leap + countingday[whatmonth] + whatdate;
			sumcontrol = year * 365 + leap + 1;
			whatday = sum - sumcontrol;
			whatday = (whatday + base)%7;
			if(whatmonth == 1 && whatdate == 1)
				printf("%d\n", base);
    		else printf("%d\n", whatday);
		}
	}
	 return 0;
} 
