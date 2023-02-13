/*
Consider an integer n on which you can perform m operations, where a single operation includes replacing every digit d of the number with the decimal representation of the integer d+1. As an example, 789 would become 8910 after applying the operation once. Find the length of the integer n after applying m operations. Since the answer can be very large, print it modulo 109+7

Consider an integer n on which you can perform m operations, where a single operation includes replacing every digit d of the number with the decimal representation of the integer d+1. As an example, 789 would become 8910 after applying the operation once.
Find the length of the integer n after applying m operations. Since the answer can be very large, print it modulo 109+7

Input Format

567 4

Output Format

5

Testcase 1
Input

1912 1

Output

5
*/
//Program --->	
//Only 3/4 TC's passed
#include<stdio.h>

int main()
{

    int num;
    scanf("%d",&num);
    

    int arr[30];
    int i= 0;
    while(num!=0)
    {
        int x = num%10;
        arr[i] = x;
        
        num = num/10;
        i++;
    }


    int n;
    scanf("%d",&n);
    int ans;
    i = i-1;
    
    for(i;i>-1;i--)
    {
        if(arr[i] + n>=10)
        {

            ans = ans*100;
        }
        else{
            ans = ans*10;
        }
        ans = ans+(arr[i]+n);
    }
    int count = 0;
    while(ans != 0)
    {
        ans = ans/10;
        count++;
    }
    count = count%(1000000000+7);
    
    printf("%d",count);
    return 0;
}
