#include <stdio.h>
#include <stdlib.h>

int main(){
	double a, b, v, w, x, y, z;
	scanf("%lf %lf %lf %lf %lf %lf %lf", &a, &b, &v, &w, &x, &y, &z);
	double max = 0;
	double ratio = 0;
	if((int) a % 2 == 0){
		if(w/a >= v/(a+1)){
			max = a;
			ratio = w/a;	
		}
		else{
			ratio = v/(a+1);
		 	max = a+1;		
		}
	}
	else{
		if(v/a >= w/(a+1)){
			ratio = v/a;
			max = a;
		}
		else {
			ratio = w/(a+1);
			max = a+1;	
		}
	}
	if((int)b%3 == 0){
		if(x/b > ratio){
			max = b;
			ratio = x/b;
		}
		if(y/(b+1) > ratio)
			max = b+1, ratio = y/(b+1);
		if(z/(b+2) > ratio)
			max = b+2, ratio = z/(b+2);		 
	}
	else if((int)b%3 == 1){
		if(y/b > ratio)
			max = b, ratio = y/b;
		if(z/(b+1) > ratio)
			max = b+1, ratio = z/(b+1);
		if(x/(b+2) > ratio)
			max = b+2, ratio = x/(b+2);	
	}
	else{
		if(z/b > ratio)
			max = b, ratio = z/b; 
		if(x/(b+1) > ratio)
			max = b+1, ratio = x/(b+1);
		if(y/(b+2) > ratio)
			max = b+2, ratio = y/(b+2);	
	}
	int ans = (int) max;
	if(v == 0 && w == 0 && x == 0 && y == 0 && z == 0)
		ans = 1;
	printf("%d", ans);	
} 
