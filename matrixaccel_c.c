#include <stdio.h>
#include <stdlib.h>


extern float getVelocity(float initialVelocity, float finalVelocity, float time);
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
	 float initialVelocity, finalVelocity, time, velocity;
	 for (j = 0; j < totalCars; j++) {
        initialVelocity = carMatrix[j][0];
        finalVelocity = carMatrix[j][1];
        time = carMatrix[j][2];
		printf("Car %d -> Initial Velocity: %.2f, Final Velocity: %.2f, Time: %.2f\n", j + 1, initialVelocity, finalVelocity, time); //for debugging only
	 	
	    velocity = getVelocity(initialVelocity, finalVelocity, time);
        printf("Car %d Velocity: %.2f\n", j + 1, velocity); 
	 }


	return 0;

}
