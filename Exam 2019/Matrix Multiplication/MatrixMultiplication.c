#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdint.h>
#include<math.h>
 
 
uint64_t power(uint64_t base, int exponent)
{
    uint64_t result = 1;
    for (exponent; exponent>0; exponent--)
    {
        result = result * base;
    }
    return result;
}
 
void printMatrix(uint64_t *matrix){
    int temp[8][8] = {0};
    int i = 0, j = 0;
    uint64_t tempval = *matrix;
    while(tempval > 0){
        if(tempval & 1 == 1){
            temp[i][j] = 1;
        }
        tempval >>= 1;
        j++;
        if(j > 7){
            i++;
            j = 0;
        }
    }
    printf("%llu\n", *matrix);
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++)
            printf("%d", temp[i][j]);
        if(i != 7)
            printf("\n");
    } 
 
}
void rotateMatrix(uint64_t *matrix){
    int temp[8][8] = {0};
    int i = 0, j = 0;
    uint64_t tempval = *matrix;
    while(tempval){
        if(tempval & 1 == 1){
            temp[i][j] = 1;
        }
        tempval >>= 1;
        j++;
        if(j > 7){
            i++;
            j = 0;
        }
    }
    int flag = 0;
    int max = 7, min = 0;
    int temp2[8][8] = {0};
    /*while(min < 4){
        for(int i = min; i<=max; i++){
            temp2[i][max] = temp[min][i];
            temp2[i][min] = temp[max][i];
            temp2[min][i] = temp[max-i][min]; 
            temp2[max][i] = temp[max-i][max];
        }
        max--, min++;
    }*/
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            temp2[i][j] = temp[j][i];
        }
    }
    int temp3[8][8] = {0};
    int ctr = 0, mctr = 7;
    while(ctr < mctr-ctr){
    for(int i = 0; i<8; i++)
        temp3[i][ctr] = temp2[i][mctr-ctr];
 
    for(int j = 0; j<8; j++)
        temp3[j][mctr-ctr] = temp2[j][ctr];
    ctr++;        
    }
    *matrix = 0;
    int cnt = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(temp3[i][j] == 1)
                *matrix += power(2, cnt);
            cnt++;
        }
    }
}
void transposeMatrix(uint64_t *matrix){
    int temp[8][8] = {0};
    int i = 0, j = 0;
    uint64_t tempval = *matrix;
    while(tempval){
        if(tempval & 1 == 1){
            temp[i][j] = 1;
        }
        tempval >>= 1;
        j++;
        if(j > 7){
            i++;
            j = 0;
        }
    }
    int flag = 0;
    int max = 7, min = 0;
    int temp2[8][8] = {0};
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            temp2[i][j] = temp[j][i];
        }
    }
    *matrix = 0;
    int cnt = 0;
    int wow = 1;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(temp2[i][j] == 1){
                *matrix += power(2, cnt);
            }
            cnt++;
        }
    }
}

