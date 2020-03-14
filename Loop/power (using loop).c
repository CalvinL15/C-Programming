#include <stdio.h>
 
int main(void)
{
    int n,i,t;
    scanf("%d\n%d", &n, &i);
    for (t = n; i>1; i--)
        t = t*n;
    printf("%d\n",t);
    return 0;
}
