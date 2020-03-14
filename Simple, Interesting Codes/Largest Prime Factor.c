// Program to print all prime factors 
#include <stdio.h> 
#include <math.h> 

// A function to print all prime factors of a given number n 
int primeFactors(long long int n) 
{ 
	int res = 0;
	if(n%2 == 0)  
		return 2;  
	int i;
	for (i = 3; i <= sqrt(n); i+=2) 
	{ 
		// While i divides n, print i and divide n 
		while (n%i == 0) 
		{ 
			res = i;
			n = n/i; 
		} 
	}
	// condition to handle when n = prime number bigger than 2
	if (n > 2) 
		res = n;
	return res;	 
} 

/* Driver program to test above function */
int main() 
{ 
	long long int n = 600851475143; 
	int res = primeFactors(n);
	printf("%d", res);
	return 0; 
} 

