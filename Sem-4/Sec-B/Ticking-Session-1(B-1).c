/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
1 number is always missing

Input Format

3
3 0 1
 
Output Format

2

Testcase 1
Input

3
3 0 1 

Output

2
*/
//Program ---->
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int s;
    scanf("%d",&s);
    int a[s];
    int fullarr[s+1]; 
    for(int j=0;j<=s;j++){
        fullarr[j]=-1;
    }

    for(int i=0;i<s;i++){
        scanf("%d",&a[i]);
        int t=a[i];
        fullarr[t]=0;
    }
    for(int k=0;k<=s;k++){
        if(fullarr[k]==-1)
         printf("%d",k);
         
    }
}