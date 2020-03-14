#include <stdio.h>
 
int main(){
    int A, B, C, D, E, F, G;
    scanf("%d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &G);
    int edges = A+B+C+D+A*E+B*E+C*E+C*F+D*F+E*G+F+G;
    int path = A*E*G + B*E*G + C*E*G + C*F + D*F;
    printf("%d\n%d", edges, path);
    return 0;
}
