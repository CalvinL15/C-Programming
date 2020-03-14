#include <stdio.h>

typedef struct{
	long long int x;
	int cnt;
} num;

void swap(num list1[10000], num list2[10000], int j, int k ){
	long long int temp = list1[j].x;
	list1[j].x = list2[k].x;
	list2[k].x = temp;
	int tmpcnt = list1[j].cnt;
	list1[j].cnt = list2[k].cnt;
	list2[k].cnt = tmpcnt;
}

void bubblesort(num list[10000], int n){
	for(int i = 0; i<n-1; i++){
		for(int j = 0; j<n-i-1; j++){
			if(list[j].cnt > list[j+1].cnt);
				swap(list, list, j, j+1);
			else if(list[j].cnt == list[j+1].cnt && list[j].x > list[j+1].x)
				swap(list, list, j, j+1);
		}
	}
}

int main(){
	int N;
	scanf("%d", &N);
	num list[N+1];
	for(int i = 0; i<N; i++){
		scanf("%lld", &list[i].x);
		list[i].cnt = 0;
		long long int temp = list[i].x;
		while(temp){
			if(temp & 1 == 1)
				list[i].cnt++;
			temp >>= 1;	
		}
	}
	bubblesort(list, N);
	for(int i = 0; i<N; i++)
		printf("%lld %d\n", list[i].x, list[i].cnt);
}
