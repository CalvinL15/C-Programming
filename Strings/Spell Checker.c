#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	scanf("%d", &N);
	char dictionary[N][101];
	for(int i = 0; i<N; i++){
		scanf("%s", dictionary[i]);
	}
	int Q;
	scanf("%d", &Q);
	char word[101];
	for(int i = 0; i<Q; i++){
		if(i != 0)
			printf("\n");
		scanf("%s ", word);
		int len = strlen(word);
		int marker = 0;
		int F = 0;
		int G = 0;
		for(int i = 0; i<N; i+=){
			if(strcmp(word, dictionary[i]) == 0){
				printf(">%s", dictionary[i]);
				G = 1, F = 1;
				break;	
			}
		}
		if(G == 0){
			for(int i = 0; i<N; i++){
				int lendict = strlen(dictionary[i]);
				if(abs(lendict-len) > 1)
					continue;
				else if(lendict > len){
					int flag = 0;
					for(int  j = 0; j<lendict; j++){
						if(strncmp(word+j, dictionary[i]+j, 1) != 0){
							flag = j;
							break;
						}
					}
					if(strncmp(word, dictionary[i], flag) == 0 && strcmp(word+flag, dictionary[i]+flag+1) == 0){
						if(marker == 0)
							printf("?");
						else printf(" ");	
						printf("%s", dictionary[i]);
						marker++;
						F = 1;
						}
				}
				else if (len > lendict){
					int flag = 0;
					for(int j = 0; j<len; j++){
						if(strncmp(word+j, dictionary[i]+j, 1) != 0){
							flag = j;
							//printf("?");
							break;
						}
					}
					if(strncmp(word, dictionary[i], flag) == 0 && strcmp(word+flag+1, dictionary[i]+flag) == 0){
						if(marker == 0)
							printf("?");
						else printf(" ");	
						printf("%s", dictionary[i]);
						marker++;
						F = 1;
					}
				}
				else{
					int flag = 0;
					for(int j = 0; j<len; j++){
						if(strncmp(word+j, dictionary[i]+j, 1) != 0){
							flag++;
							if(flag == 2)
								break;
						}
					}
					if(flag == 2)
						continue;
					else{
						if(marker == 0)
							printf("?");
						else printf(" ");
						printf("%s", dictionary[i]);
						marker++;
						F = 1;	
					}	
				}
			}
		}
		if(F == 0)
			printf("!%s", word);		
	}	
}
