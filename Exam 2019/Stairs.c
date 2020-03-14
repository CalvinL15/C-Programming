#include <stdio.h>
#include <string.h>
 
int main(){
    char n[31];
    int i = 0;
    int accumlength = 0;
    char prev = '*';
    while(scanf("%s", n) != EOF){
        i++;
        int len = strlen(n);
        if(i%2 == 1){
            if(n[0] != prev && prev != '*'){
                printf("\n");
                for(int j = 0; j<accumlength; j++)
                    printf("*");
                printf("%s", n);
                accumlength += len-1;
            }
            else if(n[0] == prev || prev == '*'){
                char temp[30];
                strcpy(temp, n+1);
                if(prev == '*'){
                    printf("%s", n);
                }
                else
                    printf("%s", temp);
                accumlength += len-1;
            }
        }
        else{
            if(n[0] != prev){
                for(int i = 0; i<len; i++){
                    printf("\n");
                    for(int j = 0; j<accumlength; j++)
                        printf("*");
                    printf("%c", n[i]);
                }
            }
            else{
                for(int i = 1; i<len; i++){
                    printf("\n");
                    for(int j = 0; j<accumlength; j++)
                        printf("*");
                    printf("%c", n[i]);    
                }
            }
        }
        prev = n[len-1];
    }
}
