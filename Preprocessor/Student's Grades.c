#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int grade, n = 0;
	double sum = 0, rank = 0;
	while(scanf("%d", &grade) != EOF){
		#ifdef HUNDRED
			n++;
			printf("%d ", grade);
			sum += grade;
		#endif
		#ifdef APLUS
			n++;
			if(grade >= 90){
				printf("A+ ");
				rank += 4.3, sum += 95;
			}
			else if(grade >= 85){
				printf("A ");
				rank += 4.0, sum += 87;
			}
			else if(grade >= 80){
				printf("A- ");
				rank += 3.7, sum += 82;
			}
			else if(grade >= 77){
				printf("B+ ");
				rank += 3.3, sum += 78;
			}
			else if(grade >= 73){
				printf("B ");
				rank += 3.0, sum += 75;
			}
			else if(grade >= 70){
				printf("B- ");
				rank += 2.7, sum += 70;
			}
			else if(grade >= 67){
				printf("C+ ");
				rank += 2.3, sum += 68;
			}
			else if(grade >= 63){
				printf("C ");
				rank += 2.0, sum += 65;
			}
			else if(grade >= 60){
				printf("C- ");
				rank += 1.7, sum += 60;
			}
			else printf("F "), sum += 50;
		#endif						
	}
	#ifdef HUNDRED
		printf("%.1f", sum/n);
	#endif
	#ifdef APLUS
		printf("%.1f %.1f", rank/n, sum/n);
	#endif
	return 0;		
}
