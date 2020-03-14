#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char strings[100];
	int digit = 0;
	int letters = 0;
	int vowels = 0;
	int consonants = 0;
	int length, i;
	scanf("%s", strings);
	length = strlen(strings);
	for(i = 0; i < length; i++){
		if(isdigit(strings[i]))
			digit++;
		else if(isalpha(strings[i])){
			letters++;	
			if(strings[i] == 'a' || strings[i] == 'i' || strings[i] == 'u' || strings[i] == 'e' || strings[i] == 'o' || strings[i] == 'A' || strings[i] == 'I' || strings[i] == 'U' || strings[i] == 'E' || strings[i] == '0')
				vowels++;
			else consonants++;			
		}	
	}
	printf("%d %d %d %d\n", digit, letters, vowels, consonants);
	return 0;
}
