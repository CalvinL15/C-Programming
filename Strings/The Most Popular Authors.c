#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int M;
	scanf("%d", &M);
	char authors[M][50];
	char books[M][50];
	char aut[50];
	int relations[100];
	int flag = 0;
	int numofauthors = 0;
	for(int i = 0; i<M; i++){
		scanf("%s %s", aut, books[i]);
		for(int j = 0; j<numofauthors; j++){
			if(strcmp(aut, authors[j]) == 0){
				relations[i] = j;
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			//authors[numofauthors] = aut;
			strcpy(authors[numofauthors], aut);
			relations[i] = numofauthors;
			numofauthors++;
		}
		flag = 0;
	}
	int totalsold[numofauthors];
	for(int i = 0; i<numofauthors; i++)
		totalsold[i] = 0;
	int numsold;
	char buku[50];
	for(int i = 0; i<M; i++){
		scanf("%s %d", buku, &numsold);
		int marker;
		for(int j = 0; j<M; j++){
			if(strcmp(buku, books[j]) == 0){
				totalsold[relations[j]] += numsold;
				break;
			}
		}
	}
	int max = -1;
	int idx = -1;
	for(int i = 0; i<numofauthors; i++){
		if(totalsold[i] > max){
			max = totalsold[i];
			idx = i;
		}
		if(totalsold[i] == max){
			if(strcmp(authors[idx], authors[i]) > 0)
				idx = i;
		}
	}
	printf("%s %d", authors[idx], max);
}
