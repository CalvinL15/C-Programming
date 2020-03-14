#include <stdio.h>
int main (){
int a, b, c, d, e, p, q, r, s, x, y, F;
int sum = 0;
 
scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
scanf("%d%d%d%d", &p, &q, &r, &s);
scanf("%d%d%d", &x, &y, &F);
    for(int i = 0; i < F; i++){
        if(x == p && y == q) {
            x = r; y = s;
            i--;
        }
        else if (x == r && y == s) {
            x = p; y = q;
            i--;
        }
        else {
            sum += (c*x + d*y)%e;
            if ((a*x + b*y) % 4 == 0){
                y += 1;
            }
            else if ((a*x + b*y) % 4 == 1){
                x += 1;
            }
            else if ((a*x + b*y) % 4 == 2){
                y -= 1;
            }
            else if ((a*x + b*y) % 4 == 3){
                x -= 1;
            }

        } 
        printf("%d\n", sum);
        printf("%d %d", x, y);
        return 0;
}