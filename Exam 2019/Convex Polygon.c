#include <stdio.h>
#include <math.h>
//this code is not intended to be read by other people, hence why it is a messy code. 
int main(){
    int N;
    scanf("%d", &N);
    double a, b, c, fx, fy;
    double distance = 0;
    scanf("%lf %lf %lf", &a, &b, &c);
    double oria = a, orib = b, oric = c;
    double prevx, prevy, d, e, f, meow1, meow2, meow3, orid, orie, orif;
    for(int i = 1; i<N; i++){
        scanf("%lf %lf %lf", &d, &e, &f);
        orid = d, orie = e, orif = f;
        //find x
        d *= b, e *= b, f *= b;
        a *= orie, b *= orie, c *= orie;
        meow1 = a - d, meow2 = c - f;
        meow1 = (-1)*meow2/meow1; //meow1 = x;
        //find y
        meow3 = -1*(c+a*meow1)/b;
        if(i == 1)
            fx = meow1, fy = meow3, prevx = meow1, prevy = meow3;
        else {
            distance += sqrt((meow1-prevx)*(meow1-prevx) + (meow3-prevy)*(meow3-prevy));
            prevx = meow1, prevy = meow3;
        }
        a = orid, b = orie, c = orif;
    }
    double orioria = oria, oriorib = orib, orioric = oric;
    oria *= b, orib *= b, oric *= b;
    a *= oriorib, b *= oriorib, c *= oriorib;
    meow1 = oria-a, meow2 = oric-c;
    meow1 = (-1)*meow2/meow1; //x
    meow3 = -1*(c+a*meow1)/b;
    distance += sqrt((meow1-prevx)*(meow1-prevx) + (meow3-prevy)*(meow3-prevy));
    distance += sqrt((meow1-fx)*(meow1-fx) + (meow3-fy)*(meow3-fy));
    printf("%.3lf", distance);
    return 0;
}
