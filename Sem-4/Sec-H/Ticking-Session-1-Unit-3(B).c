/* The affluent ambiguity

In a far off land named Arrayland, there were n hidden gems, where ith gem had value of nums[i]. The kingdom of Arrayland was circular, which means the end of the array was connected to the beginning, forming a loop. The king of Arrayland was impressed with the brilliance of a programmer named John and decided to reward his intelligence. The king told John that he would be gifted with precious gems. However, the gems were hidden in the circular loop of Arrayland and John had to find them in order to win them. The king also warned John that there were parts of the land where his gems could get stolen on this quest. Write a program in C to help John find the maximum sum of the values of the gems that he can get. 
Take the array input as : scanf("%d ", &arr[i]);

Input Format

arr_size - size of the array
arr - integer array

Output Format

maxval - integer

Testcase 1
Input

4 
1 -2 3 -2
Output

3 */

//CODE------>
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}

int circularMaxSubarraySum(int arr[], int n) {
    int max_val = arr[0];
    int curr_max = arr[0];
    int max_so_far = arr[0];
    int curr_min = arr[0];
    int min_so_far = arr[0];

    for (int i = 1; i < n; i++) {
        curr_max = max(arr[i], curr_max + arr[i]);
        max_so_far = max(max_so_far, curr_max);
        curr_min = min(arr[i], curr_min + arr[i]);
        min_so_far = min(min_so_far, curr_min);
        max_val += arr[i];
    }

    if (max_val == min_so_far) {
        return max_so_far;
    }
    else {
        return max(max_so_far, max_val - min_so_far);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = circularMaxSubarraySum(arr, n);
    printf("%d", max_sum);

    return 0;
}
