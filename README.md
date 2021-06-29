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

### Explanation of the Algorithms Used in the Code and Specifying the Cache Friendly Code
In loops i, j, k, and j, i, k, the case in the innermost iteration loop is as follows:

![Innermost Iteration Loop](https://github.com/tugbaguler/Spatial-Locality/blob/main/assets/Screenshot_1.jpg)

Hence for a fixed element C[i][j] the program iterates through A row-wise and B column-wise. 
The next loop order to look at is k, i, j, and i, k, j, and its code is given below.

![loop order ikj](https://github.com/tugbaguler/Spatial-Locality/blob/main/assets/Screenshot_2.jpg)

In this iteration, it appears that the innermost loop calculation changes as follows:

![Innermost Iteration Loop](https://github.com/tugbaguler/Spatial-Locality/blob/main/assets/Screenshot_3.jpg)

The r is used to indicate that the element that remains constant in the iteration of the innermost loop is r A[i][k]. Therefore, one for each A[i][k] is repeated sequentially on the C matrix. C[i][0], C[i][1], …, C[i][j]. In this way, consecutive row elements of C are accessed, which reduces access times. Looking at B accessed on a row basis (B[k][0], B[k][1], …, B[k][j]), B is now also spatially optimized. To summarize, by changing the loop to i, k, j, the temporal locality is obtained for A and spatial optimization for B and C.

The last loop orders are j, k, i or k, j, i.

![Innermost Iteration Loop](https://github.com/tugbaguler/Spatial-Locality/blob/main/assets/Screenshot_4.jpg)

In this the constant element is B[k][j] and for every iteration of the innermost loop the matrix C is accessed in the order. C[0][j], C[1][j] … C[i][j], i.e. column order. The matrix A is also accessed similarly. A[0][k], A[1][k] … A[i][k]. This algorithm, though less efficient than the i, k, j loop variant.

j, k, i and k, j, i are column-wise ordering, and k, i, j and i, k, j are row-wise ordering. row-wise ordering is most efficient than column-wise ordering.

The aim is to continue the experiment in the most efficient way. In the first part of the assignment, the desired cache-friendly algorithms are determined as k, i, j, and i, k, j. Therefore, the rest of the experiment was continued with the traditional method i, j, k algorithm and i, k, j which are the much faster cache-friendly algorithm.


