#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int d, e, inp;
	scanf("%d %d", &d, &e);
	int res1 = -1, res2 = -1, res3 = -1;
	int cx1 = -1, cx2 = -1, cx3 = -1;
	int flag = 0;
	while(scanf("%d", &inp) != EOF){
		int count = 0;
		int input = inp;
		while(!(input >= d && input <= e)){
			input = (input*a + b) % c;
			count++;
		}
		if(cx1 == -1)
			cx1 = count, res1 = inp;
		else if(cx2 == -1){
			if(abs(count-cx1) <= 2 && abs(count-cx1) != 0)
				cx2 = count, res2 = inp;
			else cx1 = count, res1 = inp, cx2 = -1, res2 = -1;
		}
		else{
			if(cx1 > cx2){
				if(cx1 - cx2 == 1){
					if(count - cx1 == 1 || cx2 - count == 1){
						cx3 = count, res3 = inp;
					}
					else if(abs(count-cx2) <= 2 && count != cx2){
						cx1 = cx2, res1 = res2, cx2 = count, res2 = inp;
					}
					else cx1 = count, res1 = inp, cx2 = -1, res2 = -1;
				}
				else if(cx1 - cx2 == 2){
					if(cx1 - count == 1){
						cx3 = count, res3 = inp;
					}
					else if(abs(count-cx2) <= 2 && count != cx2){
						cx1 = cx2, res1 = res2, cx2 = count, res2 = inp;
					}
					else cx1 = count, res1 = inp, cx2 = -1, res2 = -1;
				}
			}
			else{
				if(cx2 - cx1 == 1){
					if(count - cx2 == 1 || cx1 - count == 1){
						cx3 = count, res3 = inp;
					}
					else if(abs(count-cx2) <= 2 && count != cx2){
						cx1 = cx2, res1 = res2, cx2 = count, res2 = inp;
					}
					else cx1 = count, res1 = inp, cx2 = -1, res2 = -1;
				}
				else if(cx2 - cx1 == 2){
					if(cx2 - count == 1){
						cx3 = count, res3 = inp;
					}
					else if(abs(count-cx2) <= 2 && count != cx2){
						cx1 = cx2, res1 = res2, cx2 = count, res2 = inp;
					}
					else cx1 = count, res1 = inp, cx2 = -1, res2 = -1;
				}
				
			}
		}
		if(cx1 != -1 && cx2 != -1 && cx3 != -1){
			printf("%d %d %d", res1, res2, res3);
			flag = 1;
			break;
		}
	}
	if(flag == 0) printf("Not found");
	return 0;
}
