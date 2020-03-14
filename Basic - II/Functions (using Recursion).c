#include <stdio.h>

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
       return 0;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

float absoluteValue(float c){
	if (c == 0)
		return 0;
	if (c < 0)
		return c - (2*c);
	return c;	
} 

int squarenumber(int d){
	if (d == 0)
		return 0;
	return d*d;	
}

int main()
{
    int a, b;
    float c;
    scanf("%d%d%lf", &a, &b, &c);
    printf("%d\n", gcd(a, b));
    printf("%lf\n", absoluteValue(c));
    return 0;
}
