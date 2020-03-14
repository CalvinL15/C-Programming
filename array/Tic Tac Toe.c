#include <stdio.h>
 
int main(){
    int N;
    int movex;
    int movey;
    int move1, move2;
    int dummy = 0;
    int countmove = 0;
    scanf("%d", &N);
    int board[8] = {0};
    int i;
    for(i = 1; i < N; i++){
        scanf("%d %d", &move1, &move2);
        movex = move1 + 1;
        movey = move2 + 1;
        if((movex > 3) || (movex < 1) || (movey > 3) || (movey < 1))
        goto ASHIDIQ;
            if((board[0] == 1) || (board[0] == 2)){
                if((movex == 1) && (movey == 1))
                goto ASHIDIQ;
            }
            if((board[1] == 1) || (board[1]) == 2){
                if((movex == 2) && (movey == 1))
                goto ASHIDIQ;
            }
            if((board[2] == 1) || (board[2] == 2)){
                if((movex == 3) && (movey == 1))
                goto ASHIDIQ;
            }
            if((board[3] == 1) || (board[3] == 2)){
                if((movex == 1) && (movey == 2))
                goto ASHIDIQ;
            }
            if((board[4] == 1) || (board[4] == 2)){
                if((movex == 2) && (movey == 2))
                goto ASHIDIQ;
            }
            if((board[5] == 1) || (board[5] == 2)){
                if((movex == 3) && (movey == 2))
                goto ASHIDIQ;
            }
            if((board[6] == 1) || (board[6] == 2)){
                if((movex == 1) && (movey == 3))
                goto ASHIDIQ;
            }
            if((board[7] == 1) || (board[7] == 2)){
                if((movex == 2) && (movey == 3))
                goto ASHIDIQ;
            }
            if((board[8] == 1) || (board[8] == 2)){
                if((movex == 3) && (movey == 3))
                goto ASHIDIQ;
                }
         countmove++;
        if((movex == 1) && (movey == 1)) {
            if(countmove % 2 == 0)
            board[0] = 1;
            else board[0] = 2;
        }
        if((movex == 2) && (movey == 1)) {
            if(countmove % 2 == 0)
            board[1] = 1;
            else board[1] = 2;
        }
        if((movex == 3) && (movey == 1))
        {
            if(countmove % 2 == 0)
            board[2] = 1;
            else board[2] = 2;
        }
        if((movex == 1) && (movey == 2)) 
        {
            if(countmove % 2 == 0)
            board[3] = 1;
            else board[3] = 2;
        }
        if((movex == 1) && (movey == 3)) 
        {
            if(countmove % 2 == 0)
            board[6] = 1;
            else board[6] = 2;
        }
        if((movex == 2) && (movey == 2)) 
        {
            if(countmove % 2 == 0)
            board[4] = 1;
            else board[4] = 2;
        }
        if((movex == 3) && (movey == 2)) 
        {
            if(countmove % 2 == 0)
            board[5] = 1;
            else board[5] = 2;
        }
        if((movex == 2) && (movey == 3)) 
        {
            if(countmove % 2 == 0)
            board[7] = 1;
            else board[7] = 2;
        }
        if((movex == 3) && (movey == 3))
        {
            if(countmove % 2 == 0)
            board[8] = 1;
            else board[8] = 2;
        }
 
        if((board[0] == 1) && (board[1] == 1) && (board[2] == 1)){
            printf("White wins.");
            goto FUCK;
        }
        if((board[0] == 1) && (board[3] == 1) && (board[6] == 1)){
            printf("White wins.");
            goto FUCK;
        }
        if((board[0] == 1) && (board[4] == 1) && (board[8] == 1)){
            printf("White wins.");
            goto FUCK;
        }
        if((board[1] == 1) && (board[4] == 1) && (board[7] == 1)){
            printf("White wins.");
            goto FUCK;
        }
        if((board[2] == 1) && (board[5] == 1) && (board[8] == 1)){
            printf("White wins.");
            goto FUCK;
        }
        if((board[3] == 1) && (board[4] == 1) && (board[5] == 1)){
            printf("White wins.");
            goto FUCK;
        }
        if((board[6] == 1) && (board[7] == 1) && (board[8] == 1)){
            printf("White wins.");
            goto FUCK;
        }
        if((board[2] == 1) && (board[4] == 1) && (board[6] == 1)){
            printf("White wins.");
            goto FUCK;
        }
        if((board[0] == 2) && (board[1] == 2) && (board[2] == 2)){
            printf("Black wins.");
            goto FUCK;
        }
        if((board[0] == 2) && (board[3] == 2) && (board[6] == 2)){
            printf("Black wins.");
            goto FUCK;
        }
        if((board[0] == 2) && (board[4] == 2) && (board[8] == 2)){
            printf("Black wins.");
            goto FUCK;
        }
        if((board[1] == 2) && (board[4] == 2) && (board[7] == 2)){
            printf("Black wins.");
            goto FUCK;
        }
        if((board[2] == 2) && (board[5] == 2) && (board[8] == 2)){
            printf("Black wins.");
            goto FUCK;
        }
        if((board[3] == 2) && (board[4] == 2) && (board[5] == 2)){
            printf("Black wins.");
            goto FUCK;
        }
        if((board[6] == 2) && (board[7] == 2) && (board[8] == 2)){
            printf("Black wins.");
            goto FUCK;
        }
        if((board[2] == 2) && (board[4] == 2) && (board[6] == 2)){
            printf("Black wins.");
            goto FUCK;
        }
 
        ASHIDIQ:
            dummy = 0;
    }
    printf("There is a draw.");
    FUCK:
    return 0;    
}
