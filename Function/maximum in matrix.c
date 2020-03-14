int max(int array[5][5]){
	int x = array[0][0];
	int i, j;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			x = x > array[i][j] ? x : array[i][j];
		}
	}
	return x;
}
