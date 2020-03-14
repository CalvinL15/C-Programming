void count_day(int year, int day, int month, int results[7]){
	int isleap = 0;
	if(year%400 == 0 || (year%4 == 0 && year%100 != 0))
		isleap = 1;
	int lim[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(isleap == 1)
		lim[1] = 29;
	int curday = day;
	for(int i = 1; i<=month; i++){
		for(int k = 0; k<7; k++)
			results[k] = 0;
		for(int j=1; j<=lim[i-1]; j++){
			results[curday]++;
			curday++;
			if(curday == 7) curday = 0;
		}
	}
	return 0;	
}
