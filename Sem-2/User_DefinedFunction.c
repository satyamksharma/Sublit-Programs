/*Write a function to display array elements in the reverse order using pointers

Input Format

N : Size of Array, +ve integer greater than 0
E :  Array Elements 

Output Format

E' - Reversed Elements

*/
#include<stdio.h>

int arr[20], n, i;
int main(){
    int arr[10];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    
    for(i = n-1; i >= 0; i--)
        printf("%d\n", arr[i]);
    
}