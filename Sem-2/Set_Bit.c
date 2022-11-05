/*Given an integer N and a number K
Set the kth bit in N and print the result

NOTE: Do not add any prompts like "Enter a number". Directly Accept and print the results

Input Format

N 
K

Where N and K are integers

Output Format

N'

Where N' is N after setting the Kth bit.

*/
#include<stdio.h>

int main()
{
    int n=1,k,f;
    scanf("%d %d", &f, &k);
    int a=n<<(k-1);
    printf("%d", a|f);
    return 0;
}