#define maxL 1000
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Submission
{
    int subID;
    int studentID;
    char outputs[10][maxL];    
}Submission;
 
typedef struct score{
    int subID;
    int studentID;
    int score;
}Score;
 
void grading(char answer[10][maxL], Submission* sub, int num_of_submission){
    Score scoresav[num_of_submission];
    int cmp(const void *a, const void *b){
        Score *x = (Score *)a;
        Score *y = (Score *)b;
        if(x->studentID > y->studentID)
            return 1;
        if(x->studentID == y->studentID && x->subID > y->subID)
            return 1; 
       return 0;    
    }
    for(int i = 0; i<num_of_submission; i++){
        scoresav[i].subID = sub[i].subID;
        scoresav[i].studentID = sub[i].studentID;
        scoresav[i].score = 0;
        for(int j = 0; j<10; j++){
            if(strcmp(sub[i].outputs[j], answer[j]) == 0)
                scoresav[i].score+=10;
        }
    }
    qsort(scoresav, num_of_submission, sizeof(Score), cmp);
    int maxscore = -1, curid = -1;
    for(int i = 0; i<num_of_submission; i++){
        if(scoresav[i].studentID != curid && curid != -1){
            printf("Student %d gets %d in this exam.\n", curid, maxscore);
            curid = scoresav[i].studentID;
            maxscore = scoresav[i].score;    
        }
        curid = scoresav[i].studentID;  
        if(maxscore < scoresav[i].score)
            maxscore = scoresav[i].score;
        printf("Student %d gets %d with Submission %d.\n", scoresav[i].studentID, scoresav[i].score, scoresav[i].subID);
    //    curid = scoresav[i].studentID;    
    }
    printf("Student %d gets %d in this exam.", curid, maxscore);
}
