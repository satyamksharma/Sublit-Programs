/* Stabilize your portfolio

 Imagine you are a software engineer working on a stock trading platform. The platform helps traders make informed decisions by analyzing stock data. One of the analyses the platform provides is the stability of a stock's price. The stability of a stock's price is determined by how many times its price changes in a non-increasing direction. It is unstable if the price decreases from one day to the next day. To determine the stability, the platform needs to identify the number of prices that have caused instability. Write a program that returns the number of prices that should be repositioned to have a stable stock price.

Input Format

n - size of the array
arr - integer array

Output Format

stable_coeff - integer

Testcase 1
Input

5
3 5 1 6 3
Output

5 */

// code---->
#include<stdio.h>
#include<stdlib.h>

int main(){
    int size, stable_coef = 0;
    scanf("%d", &size);
    int arr[size], sorted[size];
    for(int i = 0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<size; i++){
        sorted[i] = arr[i];
    }

    for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(sorted[i] > sorted[j])
            {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    for(int i = 0; i<size; i++){
        if(!(arr[i] == sorted[i])){
            stable_coef++;
        }
    }
    printf("%d", stable_coef);
    return 0;
}