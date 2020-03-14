#include <stdio.h>
#include <string.h>

int main(void) {
	char string[50];
	scanf("%s", string);
	char *a, *b;
	for(int i = 0; i<strlen(string); i++){
		for(int j = 0; j<i; j++){
			a = &(string[i]);
			b = &(string[j]);
			((*(a) >= *(b)) || ((*(a) ^= *(b)), (*(b) ^= *(a)), (*(a) ^= *(b)) ));
		}
	}
	printf("%s", string);
	return 0;
}

