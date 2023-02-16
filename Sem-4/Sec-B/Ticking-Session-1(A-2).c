/*
Elements with unique sum

Given an array Arr of N positive integers and another number target. Determine whether or not there exist two elements in Arr whose sum is exactly equal to target. Return 1 if there exists two such elements and 0 if there aren’t.

Input Format

5 -2// number of elements 
0 -1 2 -3 1// required sum

Output Format

Yes// pair found which adds up to required sum

Testcase 1
Input

5 -2
0 -1 2 -3 1
Output

Yes
*/
//Solution 

#include <stdio.h>


int chkPair(int A[], int size, int target)

{
    int yes=0;

    // Your code here
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(A[i]+A[j]==target)
            {
                yes=1;
                //printf("Yes");
                //break;
            }
             
        }
    }
    if(yes==0)
     //printf("No");
     return 0;
    else 
     return 1;
     //printf("Yes")

}

 

 

int main(void)

{

        int n, i, target; 

        scanf("%d%d",&n,&target);

        int a[n];

        for (i = 0; i < n; i++) {

            scanf("%d",&a[i]);

        }

 	

    if (chkPair(a, n, target)) {

        printf("Yes\n");

    }

    else {

        printf("No\n");

    }

}