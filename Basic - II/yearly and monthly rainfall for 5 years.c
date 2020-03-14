#include <stdio.h>
#define MONTHS 12
#define YEARS 5
int main(){
	float rain[YEARS][MONTHS] = {
	{1.3, 2.3, 4.3, 4.2, 2.4, 4.4, 3.1, 3.2, 3.3, 6.1, 4.5, 5.2},
	{1.4, 4.3, 7.3, 4.1, 2.3, 4.2, 5.4, 4.2, 9.3, 6.4, 1.5, 11.2},
	{3.3, 0.8, 4.3, 4.2, 2.7, 4.7, 3.7, 3.7, 3.7, 7.1, 7.7, 7.2},
	{5.6, 2.9, 4.3, 4.2, 2.1, 4.1, 3.1, 1.2, 3.1, 1.1, 4.1, 4.2},
	{7.2, 6.1, 4.1, 4.1, 1.4, 1.4, 3.4, 2.2, 5.3, 10.1, 8.5, 6.2}
	}; //hard-coded data 
	int year, month;
	float TotalRainofOneYear, TotalofRainfalls;
	
	printf("YEAR\tTOTAL RAINFALL\tAVERAGE RAINFALL/MONTH (inches)\n");
	for (year = 0, TotalofRainfalls = 0; year < YEARS; year++){
		
		for (month = 0, TotalRainofOneYear = 0; month < MONTHS; month++)
			TotalRainofOneYear += rain[year][month];
		
		printf("%d\t\t%.02lf\t\t%.02lf\n", year+1, TotalRainofOneYear, TotalRainofOneYear/12);
		TotalofRainfalls += TotalRainofOneYear;
	}
	
	float yearlyaverage = TotalofRainfalls / YEARS;
	
	printf("\nThe yearly average is %0.2lf inches.\n\n", yearlyaverage);
	printf("MONTHLY AVERAGES OF RAINFALL: \n\n");
	printf("JAN   FEB   MAR   APR   MAY   JUN   JUL   AUG   SEP   OCT   NOV   DEC\n");
	for (month = 0; month < MONTHS; month++){
		for (year = 0, TotalRainofOneYear = 0; year < YEARS; year++)
			TotalRainofOneYear += rain[year][month];
		float monthlyaverage = TotalRainofOneYear/YEARS;	
		printf("%.02lf  ", monthlyaverage);	
	}
	return 0;		
		}
	
