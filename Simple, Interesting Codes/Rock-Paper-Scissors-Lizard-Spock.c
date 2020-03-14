#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int func_util(int move){
	if(move != 0 && move != 1 && move != 2)
		return 1;
	else if(move == 1){
		printf("\nSTATISTICS:\n\n");
		printf("Player's win: %d\n", yourpoint);
		printf("Computer's win: %d\n", comppoint);
		printf("Tie: %d\n", tie);
		printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");	
		return 2;
	}
	else if(move == 2)	
		return 3;
	else return 4;		
}

int main(){
	printf("Rock-Paper-Scissors-Lizard-Spock.\n\n");
	char allmove[5][10] = {"Rock", "Paper", "Scissors", "Lizard", "Spock"};
	int move;
	printf("WARNING!!! DO NOT TRY TO INPUT CHARACTERS!!! \n\n");
	printf("Do you want to view the rules of Rock-Paper-Scissors-Lizard-Spock?\nIf so, input 8. Else, press any other buttons (numbers) to continue.\n");
	scanf("%d", &move);
	if(move == 8){
		printf("Scissors cuts Paper,\nPaper covers Rock,\nRock crushes Lizard,\nLizard poisons Spock,\nSpock smashes Scissors,\nScissors decapitates Lizard,\nLizard eats Paper,\nPaper disproves Spock,\nSpock vaporizes Rock,\n(and as it always has) Rock crushes Scissors.\n");
	}
	printf("\nPick your move:\n\n");
	printf("input 0 for Rock, 1 for Paper, 2 for Scissors, 3 for Lizard, and 4 for Spock.\nIf you press any other buttons than the ones mentioned, your move will be a randomly generated move.\n");
	//scanf("%d", &move);
	srand(time(NULL));
	int yourpoint = 0, comppoint = 0, tie = 0;
	int flag = 0;
	while(flag == 0){
		scanf("%d", &move);
		if(move != 0 && move != 1 && move != 2 && move != 3 && move != 4){
			move = rand()%5;
			printf("The random move that you got is: %s.\n", allmove[move]);	
		}
		else printf("The move that you have chosen is: %s.\n", allmove[move]);	
		int comp_move = rand()%5;
		printf("The move that the computer have chosen is: %s.\n", allmove[comp_move]);
		if(move == comp_move){
			tie++;
			printf("TIE!");
			printf(" Choose your next move...\n");	
		}
		else{
			if(move == 0 && comp_move == 1){
				printf("Paper covers Rock. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				Jump:
				if(move != 0 && move != 1 && move != 2)
					flag = 1;
				else if(move == 1){
						printf("\nSTATISTICS:\n\n");
						printf("Player's win: %d\n", yourpoint);
						printf("Computer's win: %d\n", comppoint);
						printf("Tie: %d\n", tie);
						printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
						goto Jump;
				}
				else if(move == 2){
					yourpoint = 0, comppoint = 0, tie = 0;
					printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
					goto Jump;
				}	
				else printf("\nChoose your next move...\n");			
			}
			else if(move == 1 && comp_move == 0){
				printf("Paper covers Rock. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0 && move != 1 && move != 2)
					flag = 1;
				else if(move == 1){
						printf("\nSTATISTICS:\n\n");
						printf("Player's win: %d\n", yourpoint);
						printf("Computer's win: %d\n", comppoint);
						printf("Tie: %d\n", tie);
						printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
						goto Jump;
				}
				else if(move == 2){
					yourpoint = 0, comppoint = 0, tie = 0;
					printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
					goto Jump;
				}	
				else printf("\nChoose your next move...\n");	
			}
			else if(move == 0 && comp_move == 2){
				printf("Rock crushes Scissors. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0 && move != 1 && move != 2)
					flag = 1;
				else if(move == 1){
						printf("\nSTATISTICS:\n\n");
						printf("Player's win: %d\n", yourpoint);
						printf("Computer's win: %d\n", comppoint);
						printf("Tie: %d\n", tie);
						printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
						goto Jump;
				}
				else if(move == 2){
					yourpoint = 0, comppoint = 0, tie = 0;
					printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
					goto Jump;
				}	
				else printf("\nChoose your next move...\n");	
			}
			else if(move == 2 && comp_move == 0){
				printf("Rock crushes Scissors. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0 && move != 1 && move != 2)
					flag = 1;
				else if(move == 1){
						printf("\nSTATISTICS:\n\n");
						printf("Player's win: %d\n", yourpoint);
						printf("Computer's win: %d\n", comppoint);
						printf("Tie: %d\n", tie);
						printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
						goto Jump;
				}
				else if(move == 2){
					yourpoint = 0, comppoint = 0, tie = 0;
					printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
					goto Jump;
				}	
				else printf("\nChoose your next move...\n");	
			}
			else if(move == 0 && comp_move == 3){
				printf("Rock crushes Lizard. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0 && move != 1 && move != 2)
					flag = 1;
				else if(move == 1){
						printf("\nSTATISTICS:\n\n");
						printf("Player's win: %d\n", yourpoint);
						printf("Computer's win: %d\n", comppoint);
						printf("Tie: %d\n", tie);
						printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				}
				else if(move == 2){
					yourpoint = 0, comppoint = 0, tie = 0;
					printf("\nInput 0 to replay.Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				}	
				else printf("\nChoose your next move...\n");		
			}
			else if(move == 3 && comp_move == 0){
				printf("Rock crushes Lizard. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 0 && comp_move == 4){
				printf("Spock vaporizes Rock. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 4 && comp_move == 0){
				printf("Spock vaporizes Rock. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");	
				
			}
			else if(move == 1 && comp_move == 2){
				printf("Scissors cuts Paper. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 2 && comp_move == 1){
				printf("Scissors cuts Paper. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 1 && comp_move == 3){
				printf("Lizard eats Paper. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 3 && comp_move == 1){
				printf("Lizard eats Paper. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 1 && comp_move == 4){
				printf("Paper disproves Spock. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 4 && comp_move == 1){
				printf("Paper disproves Spock. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 2 && comp_move == 3){
				printf("Scissors decapitates Lizard. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 3 && comp_move == 2){
				printf("Scissors decapitates Lizard. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 2 && comp_move == 4){
				printf("Spock smashes Scissors. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 4 && comp_move == 2){
				printf("Spock smasher Scissors. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else if(move == 3 && comp_move == 4){
				printf("Lizard poisons Spock. You WIN!\n");
				yourpoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
			else{
				printf("Lizard poisons Spock. You LOSE!\n");
				comppoint++;
			//	printf("Do you want to play again? If so, press 0. Else, press any other buttons to see the statistics of the game.\n");
				printf("Input 0 to replay. Input 1 to check the statistics. Input 2 to reset the statistics. Input any other buttons to end the game.\n");
				scanf("%d", &move);
				if(move != 0)
					flag = 1;
				else printf("\nChoose your next move...\n");
			}
		}
	}
	printf("\nFINAL STATISTICS:\n\n");
	printf("Player's win: %d\n", yourpoint);
	printf("Computer's win: %d\n", comppoint);
	printf("Tie: %d\n", tie);
	return 0;
}
