#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char W[32];
	int result = 0;
	char temp[1] = "z";
	while(scanf("%s", W) != EOF){
		int len = strlen(W);
		for(int i = 0; i<len; i++){
			if(W[i] == 'a' || W[i] == 'i' || W[i] == 'u' || W[i] == 'e' || W[i] == 'o')
				continue;
			else{
				if(strncmp(temp, W+i, 1) < 0)
					result++;
				strncpy(temp, W+i, 1);	
			}	
		}
	}
	printf("%d", result);
}
