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
	long seconds;
	long nanoseconds;
	long * runtime = (long*)malloc(30*sizeof(long));;
	long timeaverage;
	//run the program 30 times to get the timeaverage
	//start time
		clock_gettime(CLOCK_MONOTONIC, &start);
		
		//calculate acceleration 
		getAcceleration(num,carMatrix,ans);
		
		//end time
		clock_gettime(CLOCK_MONOTONIC, &end);

		seconds = end.tv_sec - start.tv_sec;
		nanoseconds = end.tv_nsec - start.tv_nsec;
		seconds = seconds*1000000000;
		timeaverage = (long)seconds + (long)nanoseconds;
	
	printf("Time taken: %ld nanoseconds\n", timeaverage);
	 
	free(carMatrix);
	free(runtime);

	return 0;
}
