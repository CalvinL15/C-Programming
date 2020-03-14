#include <stdio.h>
#include <string.h>

int main(){
	int n;
	int i, j;
	scanf("%d", &n);
	char string1[80];
	char string2[80];
	for(i = 0; i < n; i++){
		int flag1 = 0, flag2 = 0;
		scanf("%s%s", string1, string2);
		int length1 = strlen(string1);
		int length2 = strlen(string2);
		if (length1 == length2){
			for(j = 0; j < length1 && flag1 == 0; j++){
				if(string1[j] != string2[j]){
					flag2++;
					if((string1[j] == string2[j+1]) && string1[j+1] == string2[j])
						flag1 = 0;
					else flag1 = 15;
					j++;	
				}
			}
			if (flag1 == 0 && flag2 <= 1)
				printf("yes\n");
			else printf("no\n");
		}
		else{
			if (length1 < length2 && length2 - length1 == 1){
				for(j = 0; j < length1 && flag2 <= 1; j++){
					if(string1[j] != string2[j+flag2]){
                        flag2++; 
                        j--;
                    }
                }
                if(flag2 <= 1) 
					printf("yes\n"); 
				else printf("no\n");	
			}
			else {
               	if(length2 < length1 && length1-length2 == 1){
                   	for(j = 0; j < length2 && flag2 <= 1; j++){
                       	if(string1[j+flag2] != string2[j]){
                           	flag2++;
                           	j--;
                       	}
                   	}
                   	if(flag2 <= 1) 
						printf("yes\n"); 
					else printf("no\n");
               	}
               	else printf("no\n");		
			}
		}
	}
	return 0;
}
