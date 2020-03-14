#include <stdio.h>

int main(){
	double basicPay;
	double hourswork;
	double grossPay;
	scanf("%lf%lf", &basicPay, &hourswork);
	if (hourswork > 40)
		grossPay = basicPay * 40 + (basicPay*1.5) * (hourswork - 40);
	else grossPay = basicPay * hourswork;	
	double taxes, netPay;
	if (grossPay <= 300)
		taxes = grossPay * 15/100;
	else if (grossPay > 450)
		taxes = (300 * 0.15) + (150 * 0.2) + ( (grossPay-450) * 0.25 );
	else taxes = (300* 0.15) + ((grossPay-300)* 0.2 );
	netPay = grossPay - taxes;
	printf("%lf\n%lf\n%lf\n", grossPay, taxes, netPay);
	return 0;	 						
}
