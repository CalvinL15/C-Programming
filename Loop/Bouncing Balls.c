#include <stdio.h>
 
int main(){
    int width;
    int height;
    int x1, y1, x2, y2;
    int dx1, dy1, dx2, dy2;
    int t;
    scanf("%d %d", &width, &height);
    scanf("%d %d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &t);
    int i;
    while(t--){
    //    x1 += dx1;
    //    y1 += dy1;
    //    x2 += dx2;
    //    y2 += dy2;
        if(x1 == x2 && y2 == y1){
            if(dx1 != dx2){
                dx1 *= -1;
                dx2 *= -1;
            }
            if(dy1 != dy2){
                dy1 *= -1;
                dy2 *= -1;
            }
 
        }
        if (x1 == 1 || x1 == width)
				dx1 = -dx1;
		if (y1 == 1 || y1 == height)
				dy1 = -dy1;
		if (x2 == 1 || x2 == width)
				dx2 = -dx2;
		if (y2 == 1 || y2 == height)
				dy2 = -dy2;
 
        x1 += dx1;
        y1 += dy1;
        x2 += dx2;
        y2 += dy2;
    }
    printf("%d\n%d\n%d\n%d\n", x1, y1, x2, y2);
    return 0;
}
