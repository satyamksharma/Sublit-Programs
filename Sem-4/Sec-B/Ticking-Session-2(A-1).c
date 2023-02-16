/*
Problem solving 1

You are given an array A of size N (N >= 4), where each element Ai of the array (Ai > 0) denotes the length of a side of a shape. Given a shape with 4 sides, find the largest perimeter you can form with the elements from the array A. Look for an O(n2) or better time complexity.

Input Format

8				// size N
4 6 1 3 6 7 9 0 	// array A

Output Format

28

Testcase 1
Input

8
4 6 1 3 6 7 9 0 
Output

28 

*/

//Solution 
#include<stdio.h>
#include<stdlib.h>
int main(){
    int size;
    scanf("%d",&size);
    int a[size];
    for(int i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    int min;
    for(int i=0;i<=size-2;i++){  
        // i 0 to n-1, j i+1 to n-2
        min=i;
        for(int j=i+1;j<=size-1;j++){
            if(a[j]<a[min]){
                min=j;
                //swap a[i],a[min]
                int temp_v=a[i];
                a[i]=a[min];
                a[min]=temp_v;

            }
        }
    }
    int sum=a[size-1]+a[size-2]+a[size-3]+a[size-4];
    printf("%d",sum);

}