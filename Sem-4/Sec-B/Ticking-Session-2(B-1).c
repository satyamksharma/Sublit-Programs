/*
Problem solving 1

You have a bag a with N coins (N > 1), where each coin i has a value of ai. You have to give a single coin to each of your two friends. To make it fair, you want the absolute value of the difference between the values of coins given to your two friends to be as small as possible.

Find the minimum possible difference between the values of the coins given to your two friends. 
Note: You can’t split a coin in two and give it to your two friends.
Aim for a time complexity of O(N*log2(N)) for N > 2

Input Format

3			// N coins
1 4 2		// bag a, ai denotes the value of the coin

Output Format

1

Testcase 1
Input

3
1 3 3 
Output

0

*/

#include<stdio.h>
#include<stdlib.h>

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
int min(int a,int b){
    return (a>b)?b:a;
}

int main(){
    int nc;
    scanf("%d",&nc);
    int bag[nc];
    for(int i=0;i<nc;i++){
        scanf("%d",&bag[i]);
    }

    //Apply merge sort
    mergeSort(bag, 0,nc- 1);

    int sum =-1;
    sum= abs(bag[0] - bag[1]);
     
    
    int sum2=0;
    sum2=abs(bag[nc-1] - bag[nc-2]);
    if(sum2<sum)
      sum=sum2;
     
    
    for (int i=1; i<nc-1; i++){
    int tempsum=0;
        tempsum += min(abs(bag[i] - bag[i-1]), abs(bag[i] - bag[i+1]));
    if(tempsum<sum)
      sum=tempsum;
    }
    printf("%d",sum);
    
}
    
