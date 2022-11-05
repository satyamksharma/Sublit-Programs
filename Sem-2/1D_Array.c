/*Write a program to sort 'N' integer values

Input Format

N- No of Inputs
A - Unsorted Input Integers 

Output Format

A'- Sorted Input Integers

*/
#include<stdio.h>

int main()
{
    int arr[50], num, x, y, temp;

    scanf("%d", &num);


    for(x = 0; x < num; x++){
        scanf("%d", arr[x]);
    }
    
    for(x = 0; x < num-1; x++)
    {
        for(y = 0; y < num-x-1; y++)
        {
            if(arr[y] > arr[y+1])
            {
                temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }
    for(x = 0; x < num; x++){
        printf("%d\n", arr[x]);
    }    
    return 0;
}