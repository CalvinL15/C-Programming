#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    int type;
    scanf("%d", &type);
    char pattern[5];
    unsigned long long int bignum = 0;
    unsigned int UI;
    unsigned short US;
    char chara[3];
    if(type == 0){
        while(scanf("%s", pattern) != EOF){
            scanf("%u %hu %s", &UI, &US, chara);
            int flag = 0;
            for(int i = 0; i<4; i++){
                if(pattern[i] == 'L'){
                    bignum <<= 32;
                    bignum += UI;    
                }
                else if(pattern[i] == 'S'){
                    bignum <<= 16;
                    bignum += US;
                }
                else if(pattern[i] == 'C'){
                    if(flag == 0){
                        bignum <<= 8;
                        bignum += chara[0];
                        flag = 1;    
                    }
                    else {
                        bignum <<= 8;
                        bignum += chara[1];
                    }
                }
            }
            printf("%llu\n", bignum);
        }
    }
    else{
        while(scanf("%s %llu", pattern, &bignum) != EOF){
            int flag = 0;
            UI = 0, US = 0;
            int shiftflag = 64;
            for(int i = 0; i<4; i++){
                if(pattern[i] == 'L'){
 
                //    UI = (bignum >>= shiftflag);
                    shiftflag -= 32; 
                    UI = (bignum >> shiftflag) - ((bignum >> shiftflag+32) << 32);
                    //shiftflag -= 32; 
                }
                else if(pattern[i] == 'S'){
                    shiftflag -= 16;
                    US = (bignum >> shiftflag) - ((bignum >> shiftflag+16) << 16);    
                }
                else{
                    shiftflag -= 8;
                    if(flag == 0){
                        chara[0] = (bignum >> shiftflag) - ((bignum >>shiftflag+8) << 8);
                        flag = 1;
                    }
                    else chara[1] = (bignum >> shiftflag) - ((bignum >>shiftflag+8) << 8);
                }
            }
            chara[2] = '\0';
            printf("%u %hu %s\n", UI, US, chara);
        }
    }
    return 0;
}
