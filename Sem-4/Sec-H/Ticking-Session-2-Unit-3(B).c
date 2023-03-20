/* A group of cars go together on a ride through the city of Hyderabad. Each car has an integer number on its number plate. The vehicles are initially in random order. The driver of the front car signals the remaining drivers behind them to overtake him and come ahead if their car number is greater than the signalling driver else they have to stay behind. The cars behind and ahead of the recent signalling driver then follow the same  pattern as 2 separate groups(Leaving the signalling driver), (Assume the last number in the array to be the first car and second last to be the 2nd car and so on). Return the final sequence of car numbers when the groups are of size one. (Average case complexity - O(N log N))

Input Format

Sample Input 1:
7			// Input Size
8 7 2 1 0 9 6		// Car numbers in the sequence of initial car arrangement

Output Format

0 1 2 6 7 8 9 */

//CODE------>

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void carRide(int n, int arr[]) {
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    carRide(n, arr);

    free(arr);

    return 0;
}