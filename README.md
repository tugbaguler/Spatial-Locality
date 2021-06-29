# Spatial-Locality
Conversion of matrix multiplication algorithm to given cache-friendly version to speed up computations.

## Cache Friendly Strategies to Optimize Matrix Multiplication
### Problem and Solution Strategy
Multiplying matrix is a simple operation. 2D arrays are created, data is inserted into them, and results 
are easily obtained using nested loops. A traditional matrix multiplication code is shown below.

![Traditional Matrix Multiplication](https://github.com/tugbaguler/Spatial-Locality/blob/main/assets/traditional_matrix_multiplication.jpg)

Most of the time, the code mentioned above is used in the codes written. When the matrix size is not determined with a high number of n, the code runs quickly, but as the value of n is increased, the code's run time will increase, so the program will run slowly. In this case, how the matrix multiplier is 
applied is very important.

When multiplying matrices, the i, j, and k parameters are usually used sequentially. But there is no rule that it will necessarily be in this ranking. If the places of these parameters change, the result will not change. However, a change occurs in the running speed of the program. In this case, matrix multiplication codes can be written in 6 different ways. The parameters that for loops will take (from the outermost to the most inward) can be
* i, j, k 
* k, j, i
* k, i, j
* j, k, i
* j, i, k
* i, k, j

### Test Results
There is a matrix multiplication code with 6 different methods. For cases where n is 16, 32, 64, 128, 256, 512, 1024, 2048, 4196, how much time each code spent running is shown in the table below.

![Comparison Elapsed Time](https://github.com/tugbaguler/Spatial-Locality/blob/main/assets/Comparison_Elapsed_Time.jpg)

When looking at the table, the working times are close to each other in areas where the n value is low, and the codes work quickly. However, as the value of n increased, the working speed of the program decreased. When n was set to 1024, it began to appear which code was running faster and which ones were slower. It is seen that k, i, j and i, k, j work much faster, k, j, i and j, i, k respectively, 
the code written works very slowly. 
Looking at the result;
* Values of i, j, k and j, i, k
* Values of i, k, j and k, i, j
* Values of k, j, i and j, k, i are closer to each other.

In this case, it can be said that different arrangements are made according to 3 different types of access.
