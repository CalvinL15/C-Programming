#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, determinant, root1,root2;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){

    determinant = b*b-4*a*c;
    if (determinant > 0)
    {
        root1 = (-b+sqrt(determinant))/(2*a);
        root2 = (-b-sqrt(determinant))/(2*a);

        printf("%.20lf %.20lf\n",root2 , root1);
    }
    else if (determinant == 0)
    {
        root1 = root2 = -b/(2*a);

        printf("%.20lf %.20lf\n", root1, root2);
    }
    else goto MEOW;
    }

	MEOW:
    return 0;
}   
