/*
Write a C program to Calculate the power of any number using recursion

Input Format

X: Input the base value.
Y: Input the value of the power.

Output Format

Z: Result

*/
#include<stdio.h>

long int Power(int x, int y);

int main()
{
    int m, n;
    scanf("%d %d", &n, &m);
    printf("%d",Power(n, m));
}

long int Power(int x, int y)
{
    long int result = 1;
    if(y==0)
    {
        return result;
    }
    else
    {
        result = x*Power(x, y-1);
    }
    return result;
}