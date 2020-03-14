#include <stdio.h>

int main(){
	int n, m; 
	int ParkingX[10], ParkingY[10], Capacity[10]; //ParkingX, Y = titik koordinat parking lot
	int BicycleX, BicycleY; //titik koordinat sepeda
	int distance;
	int i, j;
	int k;
	int Result[10] = {0}; // hasil akhir, output
	
	scanf("%d", &n);
	for(i = 0; i<n; i++){
		scanf("%d%d%d", &ParkingX[i], &ParkingY[i], &Capacity[i]);
	}
	scanf("%d", &m);
	for(j = 0; j<m; j++){
		scanf("%d%d", &BicycleX, &BicycleY);
		int MaxDistance = 80000;
		for(i = 0; i<n; i++){
			if(Capacity[i] == 0)
				continue; 
			distance = abs(ParkingX[i] - BicycleX) + abs(ParkingY[i] - BicycleY);
			if (distance < MaxDistance || distance == MaxDistance && (ParkingX[i] < ParkingX[k] || (ParkingX[i] == ParkingX[k] && ParkingY[i] < ParkingY[k])))
				{	
				// choose smaller x coordinate, choose smaller y coordinate	
				k = i;
				MaxDistance = distance;
				}
		}
		Capacity[k]--;
		Result[k]++;
	}
	
	for(i = 0; i<n; i++){
		printf("%d\n", Result[i]);
	}
	return 0;
}
