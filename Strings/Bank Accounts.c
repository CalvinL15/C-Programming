#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int N;
	scanf("%d", &N);
	int balance[N];
	int user[N][32];
	for(int i = 0; i<N; i++){
		scanf("%s %d", user[i], &balance[i]);
	}
	char name[32];
	char instructions[32];
	while(scanf("%s", name) != EOF){
		int tracker = -1;
		for(int i = 0; i<N; i++){
			if(strcmp(user[i], name) == 0)
				tracker = i;		
		}
		if(tracker == -1)
			continue;
		scanf("%s", instructions);
		int amount;
		char secuser[32];
		if(strstr(instructions, "earns") != NULL){
			scanf("%d", &amount);
			balance[tracker] += amount;
		}
		else if(strstr(instructions, "spends") != NULL){
			scanf("%d", &amount);
			if(balance[tracker] >= amount)
				balance[tracker] -= amount;
		}
		else if(strstr(instructions, "gives") != NULL){
			scanf("%s %d", secuser, &amount);
			int sectrack = -1;
			for(int i = 0; i<N; i++){
				if(strcmp(user[i], secuser) == 0)
					sectrack = i;		
			}
			if(sectrack == -1)
				continue;
			if(balance[tracker] >= amount){
				balance[tracker] -= amount;
				balance[sectrack] += amount;
			}	
				
		}
		else if(strstr(instructions, "becomes") != NULL){
			scanf("%d", &amount);
			balance[tracker] = amount;
		}
		else continue;	
	}
	for(int i = 0; i<N; i++){
		if(i != 0)
			printf("\n");
		printf("%s %d", user[i], balance[i]);
	}
}
