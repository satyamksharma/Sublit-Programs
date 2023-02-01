/* Problem solving 3

Given an array Arr of N elements and an integer K. Your task is to return the position of the last occurrence of K in the given array. If the number does not exist in the array return -1

Input Format

 5 16
 9 7 2 16 16

Output Format

4 */

// Program------>
#include <stdio.h>
#include <stdlib.h>

int last_occurrence(int arr[], int n, int k) {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == k) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = last_occurrence(arr, n, k);
    printf("%d\n", result);
    free(arr);
    return 0;
}