#include <stdio.h>
#include <stdlib.h>

int main(){
	double width, height;
	scanf("%lf%lf", &width, &height);
	double perimeter = 2 * (width + height);
	double area = width * height;
	printf("%f %f %f %f",width, height, perimeter, area); 
	return 0;
}
