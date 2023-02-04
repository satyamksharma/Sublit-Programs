/* The comic book reciprocation

Sheldon Cooper labels all his comic books with either 0 or 1 with 1 indicating that he wants to read the book in the future and 0 indicating that he never wants to read that book again. He travels 238 years into the future by building a time machine and now wants to arrange his comic books by separating all 0’s from 1’s. Return the minimum number of comic books he needs to switch in order to achieve this task.
Memory for the array must be dynamically allocated. Do not accept any spaces or new lines while accepting the input.

Explanation:
For the sample input, by interchanging the elements at position 1 and 4, the array becomes [0,0,0,1,1,1]. Hence, only one switch between the books is required.


Input Format

num_books - integer representing size of the array
books - integer array

Output Format

min_switch - integer

Testcase 1
Input

6
0 1 0 1 0 1 
Output

1 */

// Program-------->
#include<stdio.h>
#include<stdlib.h>

int sort(int* arr, int n) {
    int i = 0, j = n-1, count = 0;
    while(i<j){
        while(arr[i] == 0&& i<j){
            i++;
        }
        while(arr[j] == 1 && i<j){
            j--;
        }
        if(i<j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i =0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int c = sort(arr, n);
    printf("%d", c);
    free(arr);
    return 0;
}