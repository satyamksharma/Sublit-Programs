/* Problem solving 1

Jake Peralta, a detective in the NYPD’s 99th precinct, wants to take up a new case. However, the precinct’s captain, Raymond Holt, instructs that he cannot open a new case unless he closes all the cases he has taken so far, closing the newest cases first. Given an integer representing Jake Peralta’s cases, return 1 if he can open a new case, else return 0.

Input Format

123321

Output Format

1

Testcase 1
Input

1221
Output

1 */

// Program------>
#include <stdio.h>

int counts(n)
{
    int count;
    count = 0;
    while(n!=0){
        count++;
        n=n/10;

    }
    return count;
}
int main() {
  int n, rev = 0, rem, original;
    scanf("%d", &n);
    original = n;

    while (n != 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }

    if (original == rev && counts(original)%2==0){
        printf("1");
    }
    else
        printf("0");

    return 0;
}