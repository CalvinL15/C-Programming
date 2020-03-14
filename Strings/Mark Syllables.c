#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    char k[10000];
    int idx1, idx2;
    int f = 0;
    while(scanf("%s", k) != EOF){
        scanf("%d %d", &idx1, &idx2);
        int len = strlen(k);
        int count = 0;
        int arr[len];
        for(int i = 0; i<len; i++){
            if(k[i] == 'a' || k[i] == 'i' || k[i] == 'u' || k[i] == 'e' || k[i] == 'o'){
                arr[i] = count;
                count++;
            }
            else arr[i] = count;    
        }
    //    char prep1[len], prep2[len];
        if(f != 0)
            printf("\n");
        for(int i = 0; i<len; i++){
            if(arr[i] == idx1)
                printf("%c", k[i]);
            else printf("+");    
        }
        printf("\n");
        for(int i = 0; i<len; i++){
            if(arr[i] == idx2)
                printf("%c", k[i]);
            else printf("+");    
        }
        printf("\n");
        for(int i = 0; i<len; i++){
            if(arr[i] != idx1 && arr[i] != idx2)
                printf("%c", k[i]);
            else printf("+");    
        }
        f = 1;
    }
}
