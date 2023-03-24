/*
Problem solving 2

Implement brute force algorithm to find minimum costing tour for travelling salesman problem 

Input Format

5// number of cities
0.0  3.0  4.0  2.0  7.0
3.0  0.0  4.0  6.0  3.0
4.0  4.0  0.0  5.0  8.0
2.0  6.0  5.0  0.0  6.0
7.0  3.0  8.0  6.0  0.0 

Output Format

1 3 2 5 4 1 // min costing tour  if multiple tours with same cost are there you need to print first one as per lexicographic order

*/

#include <stdio.h>
int factorial(int a){
    if(a == 1){
        return 1;
    }
    return(a * factorial(a - 1));
}

int ascending(int arr[], int n){
    for (int i = 0; i < n; i++){
        if(arr[i] < arr[i + 1]){
            return 1;
        }
    }
    return 0;
}

void sort(int arr[], int start, int end){
    int temp;
    for(int i = start; i < end - 1; i++){
        for(int j = i + 1; j < end; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void findcost(int n, float adjmat[][n], int arr[], float costs[], int count){
    float x = 0;
    for(int i = 0; i < n; i++){
        x += adjmat[arr[i] - 1][arr[i + 1] - 1];
    }
    costs[count] = x;
}

void store(int n, int bigarr[][n], int arr[], int *count){
    for(int i = 0; i < n; i++){
        bigarr[*count][i] = arr[i];
    }
    *count = *count + 1;
}

void tsp(int arr[], int arr2[], int n, float adjmat[][n]){
    int i, j, large, count = 0;
    int permut[factorial(n - 1)][n + 1];
    float costs[factorial(n - 1)];
    arr[n] = 1;
    store(n + 1, permut, arr, &count);
    findcost(n, adjmat, arr, costs, count - 1);
    float small = costs[count - 1];
    int index_of_small = count - 1;
    while(ascending(arr2, n - 1) == 1){
        for(i = n - 2; i > 0; i--){
            if(arr2[i - 1] < arr2[i]){
                i--;
                break;
            }
        }
        large = i + 1;
        for(j = i + 1; j < n - 1; j++){
            if(arr2[i] < arr2[j] && j > large){
                large = j;
            }
        }
        j = large;
        swap(arr2, i, j);
        sort(arr2, i + 1, n-1);
        for(int k = 0; k < 4; k++){
            arr[k + 1] = arr2[k];
        }
        arr[n] = 1;
        store(n + 1, permut, arr, &count);
        findcost(n, adjmat, permut[count - 1], costs, count - 1);
        if(costs[count - 1] < small){
            small = costs[count - 1];
            index_of_small = count - 1;
        }
    }
    for(int l = 0; l <= n; l++){
        if(l != n){
            printf("%d ", permut[index_of_small][l]);
        }
        else{
            printf("%d", permut[index_of_small][l]);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    float adjmat[n][n];
    int cities[n + 1], subcities[n - 1];
    for(int i = 1; i <= n; i++){
        cities[i - 1] = i;
        if(i != 1){
            subcities[i - 2] = i;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%f", &adjmat[i][j]);
        }
    }
    tsp(cities, subcities, n, adjmat);
    return 0;
}
