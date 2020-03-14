#include <stdio.h>
 

int min(int num1, int num2, int num3);
 
int main () {

   int a = 500;
   int b = 200;
   int c = 500 - b;
   int ret;
 
   
   ret = min(a, b, c);
 
   printf( "%d\n", ret );
 
   return 0;
}
 
int min(int num1, int num2, int num3) {

   int result;
 
   if (num3 < num1 && num3 < num2)
      result = num3;
   else if (num2 < num3 && num2 < num1)
      result = num2;
      else 
      result = num1;
 
   return result; 
}
