#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	printf("This is a guessing game.\n");
	printf("I have chosen a number between 0 to 20, which you must guess.\n");
	printf("You have 5 chances to do the guessing.\n");
	time_t t;
	srand((unsigned) time (&t));
	int randNumber = rand() % 21;
	int counter = 5;

	int i, j;
	LOOP: for (i = 5; i>= 1; i--){
		int guess;
		printf("You have %d tr%s left.\n", i, i == 1 ? "y" : "ies");
		printf("Enter a guess: ");
		scanf("%d", &guess);
		for (j = i; j >= 1; j--){
			if (guess > 20 || guess < 0){
				printf("The number that you put is invalid.\n");
				goto LOOP;
			}
		} 
		if(guess < randNumber){
			counter--;
			printf("Sorry, %d is wrong. My number is greater than that.\n", guess);
		}
		else if(guess > randNumber){
			counter--;
			printf("Sorry, %d is wrong. My number is less than that.\n", guess);
		}
		else {
		printf("Congratulations. You guessed it.\n");
		break;		 
		}
		
	}
	if(counter == 0){
	printf("Unfortunately, You have failed to guess the number. The number was %d\n", randNumber);}
	return 0;
}
