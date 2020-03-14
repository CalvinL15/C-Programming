#include <stdio.h>

void fill_array(int *ptr[], int n);

int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}

void fill_array(int *ptr[], int n) {
    int *start = ptr[0];
    int *end = ptr[n-1]+1;
    int m = 0;
    for (int *p = start; p != end; p++)
        *p = -1, m++;
    for (int i = 0; i < n; i++)
        *(ptr[i]) = i;
    int prev = 0, next = 1;
    while (next < m && start[next] == -1)
        next++;
    for (int *p = start; p != end; p++) {
        if (*p == -1) {
            *p = start[prev] + start[next];
        }
          else if (start+next <= p) {
            prev = next;
              next++;
            while (next < m && start[next] == -1)
                next++;
        }      
    }
    return ;
}
