#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define _POSIX_C_SOURCE 200809L

extern void getAcceleration(int n, double* matrix, int* ans);

int main() {
    int totalCars, num, nElements;
    int col = 3;

    int j, k;

    
    scanf("%d", &totalCars);
    nElements = totalCars * col;
    num = totalCars;

    int* ans = (int*)malloc(num * sizeof(int));
    double* carMatrix = (double*)malloc(nElements * sizeof(double));

   
    for (k = 0; k < nElements; k++) {
        scanf("%lf", &carMatrix[k]);
    }

    long totalNanoseconds = 0;


    for (j = 0; j < 30; j++) {
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Convert to proper values
        getAcceleration(num, carMatrix, ans);

        clock_gettime(CLOCK_MONOTONIC, &end);
        long seconds = end.tv_sec - start.tv_sec;
        long nanoseconds = end.tv_nsec - start.tv_nsec;
        totalNanoseconds += seconds * 1000000000L + nanoseconds;
    }

    // Output average time taken
    printf("Average time taken: %ld nanoseconds\n", totalNanoseconds / 30);

    free(ans);
    free(carMatrix);

    return 0;
}
