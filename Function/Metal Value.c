int value(int type, int width, int height, int length) {
#define max(x, y) (x > y ? x : y)
	int worth[256] = {};
	worth[79] = 30, worth[47] = 10, worth[29] = 4;
	worth[82] = 5, worth[26] = 3, worth[22] = 9;
	if (type < 0 || type > 256 || worth[type] == 0)
		return -1;
	if (width <= 0 || height <= 0 || length <= 0)
		return -2;
	int price = 0, 
	int i;
	for (i = 1; i <= width && i <= height && i <= length; i++)
		if (width%i == 0 && height%i == 0 && length%i == 0)
		price = max(ret, (width/i)*(height/i)*(length/i)*i*i*i*i*i*i);
	return worth[type] * ret;
}
