#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>
 
void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
    if(method == 0){
        int idxres = 0;
        for(int i = 0; i<M; i++){
            int flag = 0;
            for(int j = 0; j<N; j++){
                if(bucket[j] >= ball[i]){
                    result[idxres] = j;    
                    bucket[j] -= ball[i];
                    idxres++, flag = 1;
                    break;    
                }
            }
            if(flag == 0)
                result[idxres] = -1, idxres++;
        }
    }
    else if(method == 1){
        for(int i = 0; i<M; i++){
            int flag = 0, min = INT_MAX, idx_bucket = -1;
            for(int j = 0; j<N; j++){
                if(bucket[j] - ball[i] >= 0 && bucket[j] - ball[i] < min)
                    result[i] = j, idx_bucket = j, min = bucket[j] - ball[i];
            }
            bucket[idx_bucket] -= ball[i];
            if(idx_bucket == -1)
                result[i] = -1;
        }
    }
    else{
        for(int i = 0; i<M; i++){
            int flag = 0, max = -1, idx_bucket = -1;
            for(int j = 0; j<N; j++){
                if(bucket[j] - ball[i] >= 0 && bucket[j] - ball[i] >= max)
                    result[i] = j, idx_bucket = j, max = bucket[j] - ball[i];
            }
            bucket[idx_bucket] -= ball[i];
            if(idx_bucket == -1)
                result[i] = -1;    
        }    
    }
}
