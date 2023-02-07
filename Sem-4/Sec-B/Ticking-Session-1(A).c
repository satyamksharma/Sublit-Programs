/* Q1
Find last occurrence

Description : Given an array Arr of N elements and an integer K. Your task is to return the position of the last occurrence of K in the given array. If the number does not exist in the array return -1.

Input Format

5 16
9 7 2 16 16

Output Format

4

Testcase 1
Input

5 16
9 7 2 16 16
 
Output

4
*/

// Program ---->
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,num;
    int arr[n];
    scanf("%d %d",&n,&num);
    for(int i=0;i<n;i++){    
        scanf("%d",&arr[i]);
    }
    int l_occur=-1;
    for(int j=0;j<n;j++){
        if(arr[j]==num){
            l_occur=j;
        }
    }
    printf("%d",l_occur);
    return 0;
}