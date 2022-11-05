/*Write a function to check whether a given number is prime and use that to find the next prime number, greater than a given number.

Input Format

X : Number to check prime or not , using this compute Y

Output Format

Y : Next Prime number*/
#include<stdio.h>

 int isprime(int n)
 {
     int i, count = 0;
     for(i = 1; i<=n; ++i)
     {
         if(n%i==0)
            count = count + 1;
     }
     if(count == 2)
         return 1;  
 }
int nextprime(int n)
{
    int a, i = n+1;
    while(1)
    {
        a = isprime(i);
        if(a == 1)
            break;
        i++;
    }
    return i;
}
 int main()
 {
     int n, x;
     scanf("%d", &n);
     printf("%d", nextprime(n));
    
 }