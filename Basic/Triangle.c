#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i;
    int m,n;
    scanf ("%d\n", &n);
    for (int m=0;m<n;m++)
    {
    scanf ("%d%d%d%d%d%d", &a,&b,&c,&d,&e,&f);
    g = ((d-b)*(d-b)+(c-a)*(c-a));
    h = ((f-d)*(f-d)+(e-c)*(e-c));
    i = ((b-f)*(b-f)+(a-e)*(a-e));
    if ((g==h)||(g==i)||(h==i))
    { printf ("isosceles\n"); }
    else if ((g)>(i+h) || (h)>(i+g) || (i)>(g+h))
    { printf ("obtuse\n"); }
    else if ((g)==(i+h)||(i)==(g+h)||(h)==(i+g))
    { printf ("right\n");}
    else
    { printf ("acute\n"); }
    }
    return 0;
}
