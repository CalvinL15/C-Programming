#include <stdio.h>
#include <stdlib.h>

int main(){
	int max = 0,max_rec = 0;
	int max_l = 0,max_r = 0;
	int asc_cnt = 1, des_cnt = 1, asc_rec = 1, des_rec = 1;
	int mode = 0, idx = 1, prev, a;
    if( scanf("%d",&prev) == EOF){
        printf("0");
		return 0;
    }
    asc_rec = idx, des_rec = idx;
    while( scanf("%d",&a) != EOF){
        idx++;
        if(a > prev){
            if(mode == 0)
                mode = 1;
            if(mode == 1)
                asc_cnt++;
            else if(mode == -1){
                if(asc_cnt != 1){
                    if(asc_cnt + des_cnt > max)
                        max = asc_cnt + des_cnt, max_l = asc_cnt, max_r = des_cnt, max_rec = asc_rec;
                    else if(asc_cnt + des_cnt == max && asc_cnt > max_l)
                        max_l = asc_cnt, max_r = des_cnt, max_rec = asc_rec;
                }
                asc_rec = idx - 1, asc_cnt = 2, mode = 1;
            }
        }
        if(a < prev){
            if(mode == 0)
                mode = -1;
            if(mode == -1)
                des_cnt++;
            else if(mode == 1){
                if(des_cnt != 1){
                    if(des_cnt + asc_cnt > max)
                        max = des_cnt + asc_cnt, max_l = des_cnt, max_r = asc_cnt, max_rec = des_rec;
                    
                    else if(des_cnt + asc_cnt == max && des_cnt > max_l)
                        max_l = des_cnt, max_r = asc_cnt, max_rec = des_rec;    
                }
                des_rec = idx - 1, des_cnt = 2, mode = -1;
            }
        }
        prev = a;
    }
    if(asc_cnt == 1 || des_cnt == 1){
        printf("0");
     	return 0;   
    }
    else if(mode == 1){
        if(des_cnt + asc_cnt > max)
            max = des_cnt + asc_cnt, max_l = des_cnt, max_r = asc_cnt, max_rec = des_rec;
        else if(des_cnt + asc_cnt == max && des_cnt > max_l)
            max_l = des_cnt, max_r = asc_cnt, max_rec = des_rec;    
    }
    else if(mode == -1){
        if(asc_cnt + des_cnt > max)
            max = asc_cnt + des_cnt, max_l = asc_cnt, max_r = des_cnt, max_rec = asc_rec;
        
        else if(asc_cnt + des_cnt == max && asc_cnt > max_l)
            max_l = asc_cnt, max_r = des_cnt, max_rec = asc_rec;   
    }
    printf("%d %d",max-1,max_rec );
}
