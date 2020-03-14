#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(){
    int a, b, c, d, e, f, g;
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
    int vol_water = a*b*d;
    int vol_block = e*f*g;
    int tot_vol = vol_water + vol_block;
    int vol_tank = a*b*c;
    int h;
    if(d == 0) printf("0");
    else if(g <= d){
        if(tot_vol > vol_tank)
            printf("%d", c);
        else{
            h = tot_vol/(a*b);
            if(h > c) 
				h = c;     
            printf("%d", h);
        }
    }
    else{
        if(a*b == e*f){
            if(g >= c)
                h = 0;
            else h = tot_vol/(a*b);
        }
        else{
            if(g <= c)
                h = tot_vol/(a*b);
            else h = vol_water/(a*b-e*f);
        }
        if(h > c) h = c;
        printf("%d", h);
    } 
       return 0;
}
