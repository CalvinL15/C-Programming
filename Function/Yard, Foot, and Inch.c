
void init(int length[3]) {
    length[0] = 0;
    length[1] = 0;
    length[2] = 0;
}
void add(int length[3], int i) {
	int x = length[2] + i;
	int y;
	if(x > 11){
		length[2] = x%12;
		length[1] += x/12;
		if(length[1] > 2){
			length[0] += length[1]/3;
			length[1] = length[1]%3;
		} 	
	}
	else length[2] = x;
	
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
	int x = lengtha[2] + lengthb[2];
	int y = lengtha[1] + lengthb[1];
	int z = lengtha[0] + lengthb[0];
	if(x < 12){
		lengthc[2] = x;	
	}
	else{
		lengthc[2] = x%12;
		y += x/12;
	}
	if(y < 3)
		lengthc[1] = y;
	else{
		z += y/3;
		lengthc[1] = y%3;
	}
	lengthc[0] = z;	
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    /* add your code */
    if(lengtha[2] - lengthb[2] >= 0)
    	lengthc[2] = lengtha[2]-lengthb[2];
    else{
    	lengtha[1]--;
    	lengthc[2] = lengtha[2]+12-lengthb[2];
	}
	if(lengtha[1] - lengthb[1] >= 0)
		lengthc[1] = lengtha[1] - lengthb[1];
	else{
		lengtha[0]--;
		lengthc[1] = lengtha[1]+3-lengthb[1];
	}
	lengthc[0] = lengtha[0]-lengthb[0];		
}
