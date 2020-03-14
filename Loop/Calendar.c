#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int year;
	int month;
	int day;
	int isleap = 0;
	scanf("%d %d %d", &year, &month, &day);
	if(month > 12 || day > 6 || month < 1 || day < 0)
		printf("invalid\n");
	else{
		if((year%4 == 0 && year%100 != 0)  || year%400 == 0)
			isleap = 1;
		printf(" Su Mo Tu We Th Fr Sa\n");
		printf("=====================\n");
		int lim;
		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			lim = 31;
		else if(month == 2){
			if(isleap == 1)
				lim = 29;
			else lim = 28;	
		}
		else lim = 30;
		int count = 1;
		if(day == 0){
			printf("%3d%3d%3d%3d%3d%3d%3d\n", count, count+1, count+2, count+3, count+4, count+5, count+6);
			count = 8;
			for(int i = count; i<=lim; i++){
				printf("%3d", count);
				count++;
				if(day == 6 && i != lim){
					printf("\n");
					day = 0;	
				}
				else day++;
			}	
		}
		else if(day == 1){
			printf("   %3d%3d%3d%3d%3d%3d", count, count+1, count+2, count+3, count+4, count+5);
			count = 7, day = 0;
			printf("\n");
			for(int i = count; i<=lim; i++){
				printf("%3d", count);
				count++;
				if(day == 6 && i != lim){
					printf("\n");
					day = 0;	
				}
				else day++;
			}
		}
		else if(day == 2){
			printf("      %3d%3d%3d%3d%3d", count, count+1, count+2, count+3, count+4);
			count = 6, day = 0;
			printf("\n");
			for(int i = count; i<=lim; i++){
				printf("%3d", count);
				count++;
				if(day == 6 && i != lim){
					printf("\n");
					day = 0;	
				}
				else day++;
			}
		}
		else if(day == 3){
			printf("         %3d%3d%3d%3d", count, count+1, count+2, count+3);
			count = 5, day = 0;
			printf("\n");
			for(int i = count; i<=lim; i++){
				printf("%3d", count);
				count++;
				if(day == 6 && i != lim){
					printf("\n");
					day = 0;	
				}
				else day++;
			}
		}
		else if(day == 4){
			printf("            %3d%3d%3d", count, count+1, count+2);
			count = 4, day = 0;
			printf("\n");
			for(int i = count; i<=lim; i++){
				printf("%3d", count);
				count++;
				if(day == 6 && i != lim){
					printf("\n");
					day = 0;	
				}
				else day++;
			}
		}
		else if(day == 5){
			printf("               %3d%3d", count, count+1);
			count = 3, day = 0;
			printf("\n");
			for(int i = count; i<=lim; i++){
				printf("%3d", count);
				count++;
				if(day == 6 && i != lim){
					printf("\n");
					day = 0;	
				}
				else day++;
			}
		}
		else{
			printf("                  %3d", count);
			count = 2, day = 0;
			printf("\n");
			for(int i = count; i<=lim; i++){
				printf("%3d", count);
				count++;
				if(day == 6 && i != lim){
					printf("\n");
					day = 0;	
				}
				else day++;
			}
		}
	printf("\n=====================\n");			
	}	
}
