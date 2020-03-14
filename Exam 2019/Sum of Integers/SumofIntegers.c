#include <stdlib.h>
#include "sumOfIntegers.h"
 
void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks){
    int idx = 0, numblocks = 0,flag = 0, idx_ans = 0, temp_res = 0, idxs = 0;
    while(flag != 2){
        if(ptrArray[idx] == NULL){
            if(flag == 1)
                flag = 2;
            else {
                flag = 1, answer[idx_ans] = temp_res;
                idxs = idx;
                idx_ans++;
                temp_res = 0;
                numblocks++;
            }
        }
        else{
            flag = 0;
            int f2 = 0;
            for(int i = idxs; i<idx; i++){
                if(ptrArray[i] == ptrArray[idx]){
                    f2 = 1;
                    break;
                }
            }
            if(f2 == 0)
                temp_res += *ptrArray[idx];
            }
        idx++;
    }
    *numberOfBlocks = numblocks;
}
