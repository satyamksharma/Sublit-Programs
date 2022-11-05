/*Write a function to reverse a given number and check whether a given number is palindrome or not.

Input Format

N is a number

Output Format

N' is a palindrome*/
#include<stdio.h>

int main(){
    int n,r=0,m,k,j;
    scanf("%d",&n);
    if(n<0)
    {
        k=-n;
        j=-n;
    }
    else
    {
        k=n;
        j=n;
    }
    while(j>0)
    {
        m=j%10;
        j=j/10;
        r=r*10+m;
    }
    if(k==r)
        printf("PALINDROME");
    else
        printf("NOT PALINDROME");
    return 0;
}