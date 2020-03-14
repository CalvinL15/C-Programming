#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void splitAndMap(char*** ptr, char* str) {
    char deli[2] = "*";
    char *start;
    int n = 0;
    int len[10] = {0};
    int head[10] = {0};
    while(ptr[n] != NULL) n++;
 
    start = strtok(str, deli);
    while(start != NULL) {
        int select = 0;
        for(int i = 0; i < n; i++) {
            if(len[i] < len[select]) {
                select = i;
            }
        }
        ptr[select][head[select]] = start;
        head[select]++;
        len[select] += strlen(start);
        start = strtok(NULL, deli);
    }
}
