#include<stdio.h>
  int prime(int, int);
  int main(){
         int n,m,isPrime=1;
         for(n=2;n<=100;++n)
         {
         isPrime = prime(n, n/2);
         if(isPrime==1)
         printf(" %d\n ",n);
         }
         return 0;
         }

  int prime(int num, int max){
         if(max == 1)
         return 1;
         else
         {
         if(num % max == 0)
         return 0;
         else
         prime(num, max-1);
         }
         }
