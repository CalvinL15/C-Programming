#include <stdio.h>

enum Company{GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

int main(){
	enum Company a;
	enum Company b;
	enum Company c;
	a = XEROX;
	b = GOOGLE;
	c = EBAY;
	printf("%d\n%d\n%d\n", a, b, c);
	return 0;
}
