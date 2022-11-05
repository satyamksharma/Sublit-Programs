/*Write a C program to generate a Pascal triangle using two-dimensional array

Input Format

N - No of rows 

Output Format

N' - Pascal Triangle

*/
#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[50][150] = {1};
    int i, j;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<i; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            printf("%d", arr[i][j]); 
            if(i-1!=j)
                printf(" ");      
        }
        puts("");    
    }
    return 0;
}