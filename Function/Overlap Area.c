#include <stdio.h>

int main(){
	int l1, b1, r1, t1;
	int l2, b2, r2, t2;
	int l3, b3, r3, t3;
	scanf("%d%d%d%d", &l1, &b1, &r1, &t1);
	scanf("%d%d%d%d", &l2, &b2, &r2, &t2);
	scanf("%d%d%d%d", &l3, &b3, &r3, &t3);
	int area1 = (r1-l1) * (t1-b1);
	int area2 = (r2-l2) * (t2-b2);
	int area3 = (r3-l3) * (t3-b3);
	int leftab = 0;
	int leftac = 0;
	int leftbc = 0;
	int rightab = 0;
	int rightac = 0;
	int rightbc = 0;
	int bottomab = 0;
	int bottomac = 0;
	int bottombc = 0;
	int topab = 0;
	int topac = 0;
	int topbc = 0;
	int areaab = 0;
	int areaac = 0;
	int areabc = 0;
	int leftabc = 0;
	int rightabc = 0;
	int topabc = 0;
	int bottomabc = 0;
	int areaabc = 0;

	if((b1 >= t2) || (b2 >= t1) || (l1 >= r2) || (l2 >= r1))
		 areaab = 0;
	else{
		if(b1 >= b2)
			bottomab = b1;
		else bottomab = b2;
		if(l1 >= l2)
			leftab = l1;
		else leftab = l2;
		if(t1 <= t2)
			topab = t1;
		else topab = t2;
		if(r1 <= r2)
			rightab = r1;
		else rightab = r2;
		areaab = (rightab - leftab) * (topab - bottomab);
	}

	if((b1 >= t3) || (b3 >= t1) || (l1 >= r3) || (l3 >= r1))
		 areaac = 0;
	else{
		if(b1 >= b3)
			bottomac = b1;
		else bottomac = b3;
		if(l1 >= l3)
			leftac = l1;
		else leftac = l3;
		if(t1 <= t3)
			topac = t1;
		else topac = t3;
		if(r1 <= r3)
			rightac = r1;
		else rightac = r3;
		areaac = (rightac - leftac) * (topac - bottomac);
	}

	if((b3 >= t2) || (b2 >= t3) || (l3 >= r2) || (l2 >= r3))
		 areabc = 0;
	else{
		if(b3 >= b2)
			bottombc = b3;
		else bottombc = b2;
		if(l3 >= l2)
			leftbc = l3;
		else leftbc = l2;
		if(t3 <= t2)
			topbc = t3;
		else topbc = t2;
		if(r3 <= r2)
			rightbc = r3;
		else rightbc = r2;
		areabc = (rightbc - leftbc) * (topbc - bottombc);
	}
	
	if((b3 >= t2) || (b2 >= t3) || (l3 >= r2) || (l2 >= r3) || (b1 >= t3) || (b3 >= t1) || (l1 >= r3) || (l3 >= r1) || (b1 >= t2) || (b2 >= t1) || (l1 >= r2) || (l2 >= r1){
	 areaabc = 0;
	}
	else{
		if(b1 >= b2 && b1 >= b3)
			bottomabc = b1;
		if(b2 >= b1 && b2 >= b3)
			bottomabc = b2;
		if(b3 >= b1 && b3 >= b2)
			bottomabc = b3;
		if(l1 >= l2 && l1 >= l3)
			leftabc = l1;
		if(l2 >= l1 && l2 >= l3)
			leftabc = l2;
		if(l3 >= l1 && l3 >= l2)
			leftabc = l3;
		if(r1 <= r2 && r1 <= r3)
			rightabc = r1;
		if(r2 <= r1 && r2 <= r3)
			rightabc = r2;
		if(r3 <= r1 && r3 <= r2)
			rightabc = r3;
		if(t1 <= t2 && t1 <= t3)
			topabc = t1;
		if(t2 <= t1 && t2 <= t3)
			topabc = t2;
		if(t3 <= t1 && t3 <= t2)
			topabc = t3;
		areaabc = (rightabc - leftabc) * (topabc - bottomabc);

	}
	int finalarea = area1 + area2 + area3 - areaab - areabc - areaac + areaabc;
	printf("%d", finalarea);
	return 0; 

}