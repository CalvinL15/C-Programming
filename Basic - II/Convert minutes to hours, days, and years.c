#include <stdio.h>
#include <stdlib.h>

int main(){
	int minutes;
	scanf("%d", &minutes);
	double hours = minutes / 60;
	double days = hours / 24;
	double years = days / 365;
	printf("%f\n%f\n%f\n", hours, days, years);
	return 0;
}
