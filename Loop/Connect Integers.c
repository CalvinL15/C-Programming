#include <stdio.h>

int main(){
	int n;
	int saver = -1;
	int sum = 0;
	int countprev = 0;
	int countcur = 0;
	int idx = 0;
	int prev = 0;
	int msbcur;
	int msbprev = prev;
	while(scanf("%d", &n) != EOF){
		msbcur = n;
		countprev = 0;
		
		while (msbprev >= 10){
			msbprev = msbprev/10;
			countprev++;
			
		}countprev++;
		countcur = 0;
		while (msbcur >= 10){
			msbcur = msbcur/10;
			countcur++;
			
		}	countcur++;
		if(countcur > saver)
			saver = countcur;
		if(prev % 10 == msbcur){
			if(idx == 1)
				sum = sum + countprev + countcur;	
			else sum = sum + countcur;
		}
		else sum = countcur;
		
		if(sum > saver)
			saver = sum;
		prev = n;
		countprev = prev;
		idx++;	
	}
	printf("%d", saver);
	return 0;
}
