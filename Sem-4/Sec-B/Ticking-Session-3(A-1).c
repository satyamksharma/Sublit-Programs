/*
Problem solving 1

Given two numbers X and Y, calculate the product between the two using the Russian Peasant multiplication method.

Input Format

Sample input:
12 14

Output Format

Sample output:
168
*/

#include<stdio.h>

int peasent(int x,int y)
{
    //int res=0;
    if(x==1)
    {
        return y;
    }
    else if(x%2!=0)
    {
        return y+peasent(x/2,2*y);
    }
    else
    {
        return peasent(x/2,2*y);
    }
    //return 0;
}
int main()
{
    int x,y,res=0;
    scanf("%d %d",&x,&y);
    res=peasent(x,y);
    printf("%d",res);
    return 0;
}
