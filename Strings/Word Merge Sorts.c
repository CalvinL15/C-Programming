#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    char init_string[100000];
    scanf("%s", init_string);
    int init_len = strlen(init_string);
    int cons_let = init_len/3;
    int cnt = 0;
    int x = 0;
    char str2[100000];
    while(scanf("%s", str2) != EOF){
        if(x != 0)
            printf("\n");
        char temp[100000];
    //    memset(temp, '\0', sizeof(temp));
        int len = strlen(str2);
        int cl = len/3;
        int count1 = 0, count2 = 0;
        int flag = 0;
        while(cl > 0 && flag < cons_let){
            if(strncmp(init_string+count1, str2+count2, 3) <= 0){
                strncpy(temp+cnt, init_string+count1, 3);
                cnt+=3, flag++;
                count1+= 3;
            //    count2+=3, cl--;    
            }
            else{
                strncpy(temp+cnt, str2+count2, 3);
                cnt+=3, count2+=3, cl--;     
            }
        }
        if(cl > 0){
            strcpy(temp+cnt, str2+count2);
            cnt += cl*3;
        }
        else{
            strcpy(temp+cnt, init_string+count1);
            cnt += (cons_let-flag-1)*3;
        }
        printf("%s", temp), x = 1;
        memset(init_string, '\0', sizeof(init_string));
        strcpy(init_string, temp);
        init_len = strlen(init_string);
        cons_let = init_len/3;
        cnt = 0;
    }
    return 0;
}
