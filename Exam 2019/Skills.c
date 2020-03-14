#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int flag = 0;
    int R;
    int A_base, A_ex, B_base, B_ex, C_base, C_ex, A_cd, B_cd, C_cd;
    int H, g;
      int uH;
    int N;
    scanf("%d", &R);
    scanf("%d %d", &H, &g);
      uH = H;
    scanf("%d %d %d", &A_base, &A_ex, &A_cd);
    scanf("%d %d %d", &B_base, &B_ex, &B_cd);
    scanf("%d %d %d", &C_base, &C_ex, &C_cd);
    scanf("%d", &N);
    int fA = 0, fB = 0, fC = 0;
    int rdA, rdB, rdC;
    int lrA = 0, lrB = 0, lrC = 0;
    int whatmove;
    int cnt = 0;
    while(R > 0){
        int max = 0;
        if(fA == 0){
            if(cnt <= A_cd)
                rdA = A_base;
            else rdA = A_base + A_ex*(cnt-A_cd);    
        }
        else{
            if(cnt-lrA-A_cd >= 0)
                rdA = A_base + A_ex*(cnt-lrA-A_cd);
            else rdA = 0;    
        }
        if(max < rdA){
            max = rdA, whatmove = 0;
        }
        if(fB == 0){
            if(cnt <= B_cd)
                rdB = B_base;
            else rdB = B_base + B_ex*(cnt-B_cd);    
        }
        else{
            if(cnt-lrB-B_cd >= 0)
                rdB = B_base + B_ex*(cnt-lrB-B_cd);
            else rdB = 0;    
        }
        if(max < rdB){
            max = rdB, whatmove = 1;
        }
        if(fC == 0){
            if(cnt <= C_cd)
                rdC = C_base;
            else rdC = C_base + C_ex*(cnt-C_cd);    
        }
        else{
            if(cnt-lrC-C_cd >= 0)
                rdC = C_base + C_ex*(cnt-lrC-C_cd);
            else rdC = 0;    
        }
        if(max < rdC){
            max = rdC, whatmove = 2;
        }
        if(max < N)
            max = N, whatmove = 3;
        if(whatmove == 0)
            lrA = cnt, fA = 1;
        else if(whatmove == 1)
            lrB = cnt, fB = 1;
        else if(whatmove == 2)
            lrC = cnt, fC = 1;
        cnt++;
        H -= max;
      //  if(H <= 0){
        printf("%d ", H);
           if(H<=0) break;
        H += g;
        if(H > uH)
            H = uH;
        R--;                                    
    }
    return 0;
}
