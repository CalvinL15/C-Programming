#include <stdio.h>

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        int A[100] = {}, B[100] = {}, C[200] = {};
        int i, j;
        for (i = n-1; i >= 0; i--)
            scanf("%d", &A[i]);
        scanf("%d", &m);
        for (i = m-1; i >= 0; i--)
            scanf("%d", &B[i]);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                C[i+j] += A[i]*B[j];
        for (i = n+m-2; i >= 0; i--)
            printf("%d%c", C[i], " \n"[i==0]);
    }
    return 0;
}
