#include <stdlib.h>
#include "computeGrade.h"
 
void computeGrade(Classes classes[2]){
    double total1[18] = {0}, total2[18] = {0};
    for(int i = 0; i<18; i++){
        for(int j = 0; j<classes[0].numStudent; j++)
                total1[i] += classes[0].student[j].score[i].rawScore;
        for(int k = 0; k<classes[1].numStudent; k++)
                total2[i] += classes[1].student[k].score[i].rawScore;
    }
    double average1[18], average2[18];
    for(int i = 0; i<18; i++){
        average1[i] = total1[i]/classes[0].numStudent;
        average2[i] = total2[i]/classes[1].numStudent;
        double r;
        if(average1[i] > average2[i]){
            r = average1[i]/average2[i];
            for(int j = 0; j<classes[0].numStudent; j++)
                classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore;
            for(int k = 0; k<classes[1].numStudent; k++){
                classes[1].student[k].score[i].scaledScore = classes[1].student[k].score[i].rawScore * r;
                if(classes[1].student[k].score[i].scaledScore > 100)
                    classes[1].student[k].score[i].scaledScore = 100;
            }
        }
        else{
            r = average2[i]/average1[i];
            for(int j = 0; j<classes[1].numStudent; j++)
                classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore;
            for(int k = 0; k<classes[0].numStudent; k++){
                classes[0].student[k].score[i].scaledScore = classes[0].student[k].score[i].rawScore * r;
                if(classes[0].student[k].score[i].scaledScore > 100)
                    classes[0].student[k].score[i].scaledScore = 100;
            }
        }    
    }
    for(int i = 0; i<classes[0].numStudent; i++){
        if(i != 0) printf("\n");
        double total = 0;
        for(int j = 0; j<18; j++){
            total += classes[0].student[i].score[j].scaledScore;    
        }
        classes[0].student[i].finalScore = total*0.06;
        printf("%s %f", classes[0].student[i].id, classes[0].student[i].finalScore);
 
    }
    for(int i = 0; i<classes[1].numStudent; i++){
        double total = 0;
        for(int j = 0; j<18; j++){
            total += classes[1].student[i].score[j].scaledScore;    
        }
        classes[1].student[i].finalScore = total*0.06;
        printf("%s %f", classes[0].student[i].id, classes[0].student[i].finalScore);
        if(i != classes[1].numStudent-1) printf("\n");
    }
    //for(int i = 0; i<classes[0].numStudent; i++)
}