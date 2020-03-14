#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int x, y, z;
    int mx, my, mz;
    int bx, by, bz;
    int isthereablackhole = 1;
    int n, moves;
    int countmoves = 1;
    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d", &mx, &my, &mz);
    scanf("%d %d %d", &bx, &by, &bz);
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &moves);
	if (moves == 1)
		x += 1;
	if (moves == 2)
		x -= 1;
	if (moves == 3)	
		y += 1;
	if (moves == 4)
		y -= 1;
	if (moves == 5)		
		z += 1;
	if (moves == 6)
		z -= 1;		
        if (abs(x-mx)+abs(y-my)+abs(z-mz) < 10)
            goto DEATH;
        if ((isthereablackhole == 1) && abs(x-bx)+abs(y-by)+abs(z-bz) < 10) {
            x = bx; 
			y = by; 
			z = bz;
            isthereablackhole = 0;
        }
        if (countmoves%5 == 0)
            printf("%d %d %d\n", x, y, z);
        countmoves ++;    
    }
    DEATH:
    return 0;
}
