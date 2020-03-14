#include <stdio.h> 
#include <string.h> 

int main() {
    char s[1024];
    while (scanf("%s", s) == 1) {
        int n = (int) strlen(s);
       // assert(n <= 1000);
        int f = 0, x = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i]; 
            if (isdigit(c)) {
                f = 1, x *= 10 + c - '0';
            } else {
                if (f)  printf("%d\n", x);
                x = 0, f = 0;
            }               
        }
        if (f)
            printf("%d\n", x);
    }
    return 0;
}

