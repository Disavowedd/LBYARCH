#include <stdio.h>
#include <stdlib.h>


extern double getVelocity();
extern int getAcceleration();


int main(){
	int totalCars;
	int col = 3; 
	
	int j,k;
	
	scanf("%d", &totalCars);
	double carMatrix[totalCars][col];
	
	for(j=0; j<totalCars; j++){
		for(k=0; k<col; k++){
			scanf("%lf", &carMatrix[j][k]);
		}
	}
}
