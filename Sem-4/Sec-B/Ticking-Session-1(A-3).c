/*
Matrix operations

Amy has been given an image in the form of a square matrix filled with integers. She needs to perform the following operation on the matrix:

Given matrix:		After operation:
1 3 4 2			1 2 3 1
2 2 2 2			3 2 1 2
3 1 5 6			4 2 5 3
1 2 3 4			2 2 6 4

Help Amy perform this operation

Input Format

4//no of rows and columns for the matrix
1 3 4 2
2 2 2 2
3 1 5 6
1 2 3 4

Output Format

1 2 3 1
3 2 1 2
4 2 5 3
2 2 6 4

Testcase 1
Input

4
1 3 4 2
2 2 2 2
3 1 5 6
1 2 3 4
Output

1 2 3 1
3 2 1 2
4 2 5 3
2 2 6 4

*/

//Solution

#include <stdio.h>


void PerformOperation(int N,int A[][N], int B[][N])

{

    // Your code here
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            B[i][j]=A[j][i];
        }
    }

}


int main(void)

{

    int N;

    scanf("%d",&N);


    int A[N][N];

    int B[N][N];

 

    for(int i=0; i<N; i++) {

      for(int j=0;j<N;j++) {

         scanf("%d", &A[i][j]);

      }

    }


    PerformOperation(N, A, B);


    //print the matrix B

   //int c=0;
    for (int i = 0; i < N; i++) {
        int c=1;
        for (int j = 0; j < N; j++){

         if(c%4!=0)
            printf("%d ", B[i][j]);
         else
           printf("%d",B[i][j]);
         c++;

        }

        printf("\n");

    }

}