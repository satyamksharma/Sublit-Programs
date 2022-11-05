/*Write a program to compute the GCD of 3 numbers

Input Format

A,B, C are the numbers for which GCD is to be computed

Output Format

S - Greatest Common Divisor*/
#include<stdio.h>

int gcd(int a, int b);

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int res = gcd(a, gcd(b, c));
    printf("%d", res);
}