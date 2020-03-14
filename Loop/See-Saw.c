#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N[2048];
    int n;
    int left = 0;
	int right = 0;
	int leftweight = 0, rightweight = 0;
	int i, j, k;
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n; i++) {
        	scanf("%d", &N[i]);
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++){
                right += N[j];
				rightweight += (j+1)*N[j];
        	}
            for (int j = 0; j < n; j++) {
                leftweight += left;
				rightweight = rightweight - right;
                left += N[j];
				right -= N[j];
                if (leftweight == rightweight) {
                    for (k = 0; k < j; k++)
                        printf("%d ", N[k]);
                    printf("v");
                    for (k = j+1; k < n; k++)
                        printf(" %d", N[k]);
                    puts("");   
					goto END; 
                }
            }
            {int t = N[i]; N[i] = N[n-1-i], N[n-1-i] = t;}
        }
        END:;
    }
    return 0;
}

