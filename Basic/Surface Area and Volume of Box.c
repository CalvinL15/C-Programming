#include <stdio.h>
 
int main(void)
{
    int a,b,c,d,e;
    int volume, area;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
 
    area = 2*((a*b) + (a*c) + (b*c)) + 4*((d*((a-2*e)+(c-2*e))) + (d*((b-2*e)+(c-2*e))) + (d*((b-2*e)+(a-2*e))));
    volume = (a*b*c) - 2*((d*(a-2*e)*(c-2*e)) + (d*(b-2*e)*(c-2*e)) + (d*(b-2*e)*(a-2*e)));
    printf("%d\n%d\n",area,volume);
    return 0;
}
