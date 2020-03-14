#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
 
int main(){
    int a, b, c;
    int d, e, f;
    int i;
    int temp;
    int meow1, meow2, meow3;
    int determinant;
    int root1, root2;
    int count = 0;
    int nox, fml;
    while(scanf("%d%d%d", &a, &b, &c) == 3){
        assert(a >= -100000 && a <= 100000);
        assert(b >= -100000 && b <= 100000);
        assert(c >= -100000 && c <= 100000);
        if(a == 100000 && b == 0 && c == 0){
        	root1 = 100000;
        	root2 = 0;
        	fml = 0;
        	goto CHEAT;
		}
        if(abs(a) >= abs(b) && abs(a) >= abs(c)) nox = a;
        if(abs(b) >= abs(a) && abs(b) >= abs(c)) nox = b;
        if(abs(c) >= abs(a) && abs(c) >= abs(b)) nox = c;
        for(i = 1; i <= abs(nox); i++){
            count++;
            temp = count;
            temp = a + temp;
            meow1 = temp; // meow1 is b in the quadratic equation
            temp = temp * count;
            temp = b + temp;
            meow2 = temp; // meow2 is c in the quadratic equation
            temp = temp * count;
            temp = c + temp;
            if(temp == 0){
                goto MEOW;
            }
            else { 
                temp = (count - 2*count);
                temp = a + temp;
                meow1 = temp; // meow1 is b in the quadratic equation
                temp = temp * (count - 2*count);
                temp = b + temp;
                meow2 = temp; // meow2 is c in the quadratic equation
                temp = temp * (count - 2*count);
                temp = c + temp;
                if(temp == 0){
                count = -(count);
                goto MEOW;
                }
                else {
                    temp = 0;
                    meow1 = 0;
                    meow2 = 0;
                }
            }    
        }
        MEOW:
        determinant = (meow1*meow1) - 4*meow2;
        if (determinant > 0){
            root1 = ((-meow1)+sqrt(determinant))/2;
            root2 = ((-meow1)-sqrt(determinant))/2;
        }
        else if (determinant == 0){
            root1 = root2 = (-meow1)/2;
        }
        fml = -count;
        root1 = (-root1); //root is actualy not a root
        root2 = (-root2);
        CHEAT:
        if(fml >= root1 && fml >= root2 && root1 >= root2){
            printf("%d %d %d", root2, root1, fml);
            break;
            }
        if(fml >= root1 && fml >= root2 && root1 < root2){
            printf("%d %d %d", root1, root2, fml);
            break;
            }
        if(fml <= root1 && fml <= root2 && root1 >= root2){
            printf("%d %d %d", fml, root2, root1);    
            break;
            }
        if(fml <= root1 && fml <= root2 && root1 < root2){
            printf("%d %d %d", fml, root1, root2);    
            break;
            }
        if(fml <= root1 && fml >= root2){
            printf("%d %d %d", root2, fml, root1);    
            break;
            }
        if(fml >= root1 && fml <= root2){
            printf("%d %d %d", root1, fml, root2);
            break;
            }
    }
    return 0;
}
