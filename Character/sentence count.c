#include <stdio.h>
#include <string.h>
 
int main(void){
    int sentencecount = 0;
    // int space = 0;
    char str[10000];
	char strA, strB;
     
    while(scanf("%s",str) != EOF){
        if(str[strlen(str)-1] == '.'){
            scanf("%c%c", &strA, &strB);
            if((strA == ' ' && strB == ' ') || strA == '\0' || strA == '\n') 
			sentencecount++;
        }
    }
    printf("%d\n",sentencecount);
    return 0;
}
