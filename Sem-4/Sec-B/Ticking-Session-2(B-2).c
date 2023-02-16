/*
Problem solving 2

You are given an integer array A of length N, and an integer X (X > 0 and X <= N). Find the Xth smallest element in the array.
Aim for a time complexity of O(N*log2(N)) for N > 2.

Input Format

9					// Size of the array, N
3 2 3 1 2 4 5 5 6 	// Elements of the array A
4 					// X

Output Format

3 

Testcase 1
Input

10
1 1 1 2 3 4 5 6 7 8
9 
Output

7 

*/

#include <stdio.h>
#include <stdlib.h>
  

void merge(int arr[], int l, 
           int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
   
    int L[n1], R[n2];
  

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    
    i = 0; 
  
    j = 0; 
  
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  

void mergeSort(int arr[], 
               int l, int r)
{
    if (l < r) 
    {
      
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}
int main(){
    int size;
    scanf("%d",&size);
    int a[size];
    for(int i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    int x;
    scanf("%d",&x);
    mergeSort(a, 0,size - 1);

    printf("%d",a[x-1]);

}