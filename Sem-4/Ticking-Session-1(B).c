/* problem solving 2

Joey Tribbiani wants to learn simple addition and in order to do this, he has to read each digit in a number and increment the number by one and write the resultant number. Help Joey achieve this task by writing a function that reads an array of digits, adds one to the number constituted by the digits and returns an array with each element being the digit of the resultant number.

Input Format

3// size of array
1 2 3 // array of one digit numbers

Output Format

1 2 4 // array of one digit numbers

Testcase 1
Input

3
9 9 9 
Output

1 0 0 0 
Testcase 2
Input

3
1 2 3  
Output

1 2 4  */

// Program------>

#include <stdio.h>

int main() {
    int n, sum=0, r, size;
    scanf("%d", &size);
    int count=0;
    int arr[10];
    for(int i=0;i < size; i++) {
        scanf("%d",&n);
        sum = sum*10 + n;
    } sum++;

    while(sum > 0) {
        r = sum % 10;
        arr[count] = r;
        sum = sum / 10;
        count++;
    } count--;

    for(int i = count; i > -1; i--)
        printf("%d ", arr[i]);

    return 0;
}