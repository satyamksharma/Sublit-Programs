/* The organization conundrum

Harry Styles’ team has come up with a new arrangement for management for Coachella 2023. During ticket booking, they will issue a number.  The binary encoding of the number will decide how people will be seated next to each other in a row and the positions of the barricades separating the people during the concert. The 0’s in the encoding represents barricades and the 1’s represent people. Return the maximum distance between two people across the barricades if any, else return the maximum distance between two people in a row.
Distance between two consecutive people is 1.

Explanation: In the given sample test case, binary encoding of 13 is 1101. The distance between 1 at position 0 and 1 at position 1 is 1. The distance between 1 at position 1 and 1 at position 3 is 2. The distance between 1 at position 0 and 1 at position 3 is not considered as there is another 1 in between these two 1’s. In other words, distance between two 1’s should be considered if there are only 0’s or nothing in between them.


Receive the integer input without any space or newline as scanf("%d", &n) 

Input Format

n - Integer

Output Format

max_dist - Integer

Testcase 1
Input

13
Output

2 */

// Program------->
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int n, temp, lastPos = -1, max = 0, distance;
    scanf("%d", &n);
    temp = n;

    char bin[32];
    int i = 0;
    while(temp > 0){
        bin[i] = (temp % 2) +'0';
        temp /= 2;
        i++;
    }
    bin[i] = '\0';

    int len = strlen(bin);
    for(i = 0; i< len/2; i++){
        char temp = bin[i];
        bin[i] = bin[len - i - 1];
        bin[len - i - 1] = temp;

    }

    for(i = 0; i<len; i++){
        if(bin[i] == '1'){
            if(lastPos == -1){
                lastPos = i;
            }
            else{
                distance = i - lastPos;
                if(distance > max){
                    max = distance;
                }
                lastPos = i;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}