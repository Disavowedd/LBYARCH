#include <stdio.h>
#include <stdlib.h>


extern float getVelocity(float initialVelocity, float finalVelocity, float time);
extern void getAcceleration(int n, double* matrix, int* ans);


int main(){
	int totalCars, num, nElements;
	int col = 3; 
	
	int j,k;
	
	scanf("%d", &totalCars);
	nElements = totalCars * col;
	num = totalCars;
	
	int* ans =(int*)malloc(num*sizeof(int));
	double* carMatrix =(double*)malloc(nElements*sizeof(double));

	//get input
	for(k=0; k<nElements; k++){
		scanf("%lf", &carMatrix[k]); 
	}
	
	//convert to proper values
	getAcceleration(num,carMatrix,ans);
	
	for(k=0; k<num; k++){
		printf("%d - acceleration = %d\n", k, ans[k]);
	}
	 
	return 0;

}
