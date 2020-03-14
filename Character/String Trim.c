#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	char S[100];
	int counter = 0;
	int meow = 0;
	//scanf("%s", S);
	int i;
	while(fgets(S, 100, stdin) != NULL){
		int kim = strlen(S);
		for(int j = kim; j>0; j--){
			if (isspace(S[j])
		 		meow += 1;
		 	if !(isspace(S[j]))	
		 		break;
		}
		for(i = 0; i<kim-meow; i++){
			 if (isspace(S[i]) && counter == 0)
		 		continue;
		 	else counter = 1;	
		 	if(counter == 1 || !(isspace(S[i]))) {
		 		printf("%c", S[i]);
		 		}
			}
		counter = 0;	
	}
	return 0;
}