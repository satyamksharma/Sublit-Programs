/* Delivering success

Imagine you are a software engineer working on a logistics company's delivery system. The company uses a fleet of vehicles to deliver packages to customers. The packages are identified by a unique tracking number. One day, the company received a large number of packages, and they needed to sort the packages based on their tracking numbers. The tracking numbers are stored in an array. The company has a specific rule for sorting the packages: the packages with tracking numbers in odd positions in ascending order and even positions in descending order. Write a program that takes an array of integers as input and returns a new array that follows the company's sorting rule.

Input Format

n - size of array
arr - integer array

Output Format

out_arr - integer array

Testcase 1
Input

4
4 3 2 1
Output

2 3 4 1

 */

// Code------->

#include<stdio.h>

int main(){
    int n, temp, i, j;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i< n; i++){
        scanf("%d", &arr[i]);
    }

    for(i = 0; i<n; i++)
    {
        for(j = i+2; j< n; j+=2)
        {
            if(i%2 == 0){

                if(arr[j] < arr[i])
                {
                    temp = arr[i]; 
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            else {
                if(arr[j] > arr[i])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    for(i = 0; i< n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}