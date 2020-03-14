#include <stdio.h>
#include <string.h>
 
int main(){
    int sum;
	int odd,even;
	int last;
	int i;
    char number[1000];
     
    scanf("%s",number);
    while(strcmp(number,"-1") != 0)
    {
        sum = 0;
        odd = 0;
        even = 0;
        int length = strlen(number);
         
        for(i = 0; i < length; i++)
        {
            int temp = number[i] - '0';
            sum += temp;
            if(i == length-1) 
				last = temp;
            if(i%2 == 1) 
				odd += temp; 
			else even += temp;
        }   
     
        if(last % 2 == 0) printf("yes "); else printf("no ");
        if(sum % 3 == 0) printf("yes "); else printf("no ");
        if(last == 0 || last == 5) printf("yes "); else printf("no ");
        if((even - odd)%11 == 0) printf("yes\n"); else printf("no\n");
         
        scanf("%s",number);
    }
 
    return 0;
}
