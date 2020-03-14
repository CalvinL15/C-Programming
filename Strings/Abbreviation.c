#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char abbrev[2];
	char string[128];
	while(scanf("%s", string) != EOF){
		int len = strlen(string);
		if(strcmp(string, "the") == 0 || strcmp(string, "of") == 0 || strcmp(string, "and") == 0 || strcmp(string, "at") == 0)
			continue;
		if(strcmp(string, "the.") == 0 || strcmp(string, "of.") == 0 || strcmp(string, "and.") == 0 || strcmp(string, "at.") == 0){
			printf("\n");	
			continue;	
		}
		else printf("%c", toupper(string[0]));
		if(string[len-1] == '.')
			printf("\n");
	}
}
