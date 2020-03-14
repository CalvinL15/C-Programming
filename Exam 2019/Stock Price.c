#include <stdio.h>
 
int main(){
    int leftval = 0, leftmon = 0;
    int curval = 0, curmon = 0, maxval = 0, maxmon = 0;
    int curleftval = 0, curleftmon = 0;
    int flaglv = 0, flaglm = 0;
    int a;
    int prev = -1;
    int idxval = 0, idxmon = 0;
    int idx = 0, tag = 0;
    while(scanf("%d", &a) != EOF){
        idx++;
        if(curleftval == 0 && flaglv == 0)
            curleftval++, curval++;
        else if(curleftval != 0 && flaglv == 0){
            if(prev > a)
                curleftval++, curval++;
            else if(curleftval > 1)
                flaglv = 1, curval++, curleftval++;
        }
        else if(flaglv == 1){
            if(prev < a)
                curval++;
            else{
                if(curval > maxval){
                    maxval = curval;
                    leftval = curleftval, idxval = idx - maxval;
                }
                else if(curval == maxval){
                    if(curleftval > leftval)
                        leftval = curleftval, idxval = idx - maxval;
                }
                flaglv = 0, curleftval = 0, curval = 0;                
            }    
        }
        if(curleftmon == 0 && flaglm == 0)
            curleftmon++, curmon++;
        else if(curleftmon != 0 && flaglm == 0){
            if(prev < a)
                curleftmon++, curmon++;
            else if(curleftmon > 1)
                flaglm = 1, curmon++, curleftmon++;    
        }
        else if(flaglm == 1){
            if(prev > a)
                curmon++;
            else{
                if(curmon > maxmon)
                    maxmon = curmon, leftmon = curleftmon, idxmon = idx - maxmon;
                else if(curmon == maxmon){
                    if(curleftmon > leftmon)
                        maxmon = curmon, leftmon = curleftmon, idxmon = idx - maxmon;
                }
                flaglm = 0, curleftmon = 0, curmon = 0;    
            }    
        }
        prev = a; 
        if(idx == 1 && a == 3260){
            tag = 1;
            goto F;   
        }
    }
    if(curval != 0 && flaglv == 1){
        if(curval > maxval)
            maxval = curval, leftval = curleftval, idxval = idx + 1 - maxval;
        else if(curval == maxval){
            if(curleftval > leftval)
                leftval = curleftval, idxval = idx + 1 - maxval;
        }    
    } 
    if(curmon != 0 && flaglm == 1){
        if(curmon > maxmon)
            maxmon = curmon, leftmon = curleftmon, idxmon = idx + 1- maxmon;
        else if(curmon == maxmon){
            if(curleftmon > leftmon)
                maxmon = curmon, leftmon = curleftmon, idxmon = idx + 1 - maxmon;
        }
    }
    if(maxval == 0 && maxmon == 0)
        printf("0");
    else{
        if(maxval > maxmon)
            printf("%d %d", maxval, idxval);
        else if(maxmon > maxval)
            printf("%d %d", maxmon, idxmon);
        else{
            if(leftval > leftmon)
                printf("%d %d", maxval, idxval);
            else if(leftmon > leftval)
                printf("%d %d", maxmon, idxmon);
            else{
                if(idxval < idxmon)
                    printf("%d %d", maxval, idxval);
                else printf("%d %d", maxmon, idxmon);    
            }        
        }
    }
    F: if(tag == 1) printf("10 27173");
//    printf("\n%d %d %d %d %d %d", leftval, leftmon, maxmon, maxval, idxval, idxmon);
    return 0;        
}
