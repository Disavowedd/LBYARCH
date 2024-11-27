#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define _POSIX_C_SOURCE 200809L

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

		struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
	//convert to proper values
	getAcceleration(num,carMatrix,ans);
	clock_gettime(CLOCK_MONOTONIC, &end);
	long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;

	for(k=0; k<num; k++){
		printf("%d - acceleration = %d\n", k, ans[k]);
	}

	printf("Time taken: %ld seconds %ld nanoseconds\n", seconds, nanoseconds);
	 
	free(carMatrix);
	free(runtime);

	return 0;
}
