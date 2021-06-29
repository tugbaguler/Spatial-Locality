#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define n 256  // matrix size

// 2D matrix
double A[n][n];
double B[n][n];
double C[n][n];
int temp ;

int main() {

    struct timespec s, e; // start and end
    double time; // result of elapsed time

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = (double) rand() / (double) RAND_MAX;
            B[i][j] = (double) rand() / (double) RAND_MAX;
            C[i][j] = 0;
        }
    }
    // create 6 different for loop for matrix multiplication
    // traditional matrix multiplication (ijk)	
    clock_gettime(CLOCK_REALTIME, &s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j]=0; 
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_REALTIME, &e);
    time = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1000000000.0;
    printf("Elapsed time: %f \n", time);
    
    // kji
    clock_gettime(CLOCK_REALTIME, &s);
    for ( int k = 0; k <n; k ++) { 
        for ( int j = 0; j <n; j ++) { 
            temp = B[k][j]; 
            for ( int i = 0; i <n; i ++) { 
                C [i] [j] += A [i] [k] * temp; 
            } 
        } 
    }
    clock_gettime(CLOCK_REALTIME, &e);
    time = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1000000000.0;
    printf("Elapsed time: %f \n", time);

    // kij
    clock_gettime(CLOCK_REALTIME, &s);
    for ( int k = 0; k <n; k ++) { 
        for ( int i = 0; i <n; i ++) { 
            temp = A[i][k];
            for ( int j = 0; j <n; j ++) { 
                C [i] [j] += temp * B [k] [j]; 
            } 
        } 
    }
    clock_gettime(CLOCK_REALTIME, &e);
    time = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1000000000.0;
    printf("Elapsed time: %f \n", time);
  
    // jki
    clock_gettime(CLOCK_REALTIME, &s);
    for ( int j = 0; j <n; j ++) { 
        for ( int k = 0; k <n; k ++) { 
            temp = B[k][j]; 
            for ( int i = 0; i <n; i ++) { 
                C [i] [j] += A [i] [k] * temp; 
            } 
        } 
    }
    clock_gettime(CLOCK_REALTIME, &e);
    time = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1000000000.0;
    printf("Elapsed time: %f \n", time);

    // jik
    clock_gettime(CLOCK_REALTIME, &s);
    for ( int j = 0; j <n; j ++) { 
        for ( int i = 0; i <n; i ++) { 
            C[j][i]=0; 
            for ( int k = 0; k <n; k ++) { 
                C [i] [j] += A [i] [k] * B [k] [j]; 
            } 
        } 
    }
    clock_gettime(CLOCK_REALTIME, &e);
    time = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1000000000.0;
    printf("Elapsed time: %f \n", time);
 
    // ikj
    clock_gettime(CLOCK_REALTIME, &s);
    for ( int i = 0; i <n; i ++) { 
        for ( int k = 0; k <n; k ++) { 
            temp = A[i][k];
            for ( int j = 0; j <n; j ++) { 
                C [i] [j] += temp * B [k] [j]; 
            } 
        } 
    }
    clock_gettime(CLOCK_REALTIME, &e);
    time = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1000000000.0;
    printf("Elapsed time: %f \n", time);


    return 0;
}