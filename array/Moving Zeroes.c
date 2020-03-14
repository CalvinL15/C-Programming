#include <stdio.h>

int main() {
    int A[100005];
    int n, i, count = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &A[i]);
        if(A[i] != 0)
        	A[count++] = A[i];
        }

    while(count < n)
        	A[count++] = 0;

    for (i = 0; i < n; i++)
        printf("%d%c", A[i], " \n"[i==n-1]);
    
    return 0;
}