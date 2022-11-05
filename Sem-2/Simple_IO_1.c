/*Given Integers, A and B

Print (A+B) * (A - B)

NOTE: Do not add any prompts like "Enter a number". Directly Accept and print the results

Input Format

A
B

Where A and B are Integers

Output Format

C

Where C = (A + B) * (A - B)*/

#include<stdio.h>

int main()
{
    int A,B,outp;
    scanf("%d %d", &A, &B);
    outp=A*A-B*B;
    printf("%d", outp);
    return 0;
}