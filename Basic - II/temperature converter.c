#include <stdio.h>

int main(){
	double celsius;
	scanf("%lf", celsius);
	double reamur = 4/5 * celsius;
	double fahrenheit = 9/5 * celsius + 32;
	double kelvin = 273.15 + celsius;
	printf("%lf\n%lf\n%lf\n", reamur, fahrenheit, kelvin);
	return 0;
}
