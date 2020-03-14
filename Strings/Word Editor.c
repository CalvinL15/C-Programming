#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    char S[100000];
    scanf("%s", S);
    char command[20];
//    char resultados[100000];
    int flag = 0;
    while(scanf("%s", command) != EOF){
        char temp[100000];
        memset(temp, 0, 100000);
    //    strcpy(temp, S);
        if(strcmp(command, "replace") == 0){
            char x[1], y[1];
            scanf("%s %s", x, y);
            int len = strlen(S);
            for(int i = 0; i<len; i++){
                if(S[i] == x[0]){
                    temp[i] = y[0];
                }
                else temp[i] = S[i];
            }
        }
        else if(strcmp(command, "remove") == 0){
            char x[1];
            scanf("%s", x);
            int count = 0;
            int len = strlen(S);
            for(int i = 0; i<len; i++){
                if(S[i] != x[0]){
                    temp[count] = S[i];
                    count++;
                }
            }
        //    printf("%s\n", temp);
        }
        else if(strcmp(command, "addhead") == 0){
            char x[1];
            scanf("%s", x);
            temp[0] = x[0];
            strcpy(temp+1, S); 
        }
        else if(strcmp(command, "addtail") == 0){
            char x[1];
            scanf("%s", x);
        //    temp[0] = x[0];
            strcpy(temp, S);
            int len = strlen(S);
            temp[len] = x[0];
 
        }
        else if(strcmp(command, "end") == 0)
            break;
        else{
            flag = 1;
            printf("invalid command %s", command);
            break;
        }
        strcpy(S, temp);
    }
    if(flag != 1)
        printf("%s", S);
}
