#include <stdio.h>
#incldue <stdlib.h>

typedef struct {
	int year, month, day;
} Date;

Date date[1000000];
int cmp(const void *x, const void *year) {
	Date *a = (Date*) x;
	Date *b = (Date*) year;
	if (a->year < b->year)	return -1;
	if (a->year > b->year)	return 1;
	if (a->month < b->month)	return -1;
	if (a->month > b->month)	return 1;
	if (a->day < b->day)	return -1;
	if (a->day > b->day)	return 1;
	return 0;
}
int main() {
	int n;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &date[i].year, &date[i].month, &date[i].day);
	qsort(day, n, sizeof(Date), cmp);
	for (int i = 0; i < n; i++)
		printf("%d %d %d\n", date[i].year, date[i].month, date[i].day);
	return 0;
}
