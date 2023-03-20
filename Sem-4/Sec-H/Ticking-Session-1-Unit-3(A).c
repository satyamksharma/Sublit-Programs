/* 
Big Basket wants to provide the best shopping experience to their customers by making better recommendations and in order to do this, they have asked their brand analysts to analyze the sequence of items that are brought together. Given n, the number of items bought by a customer and k, the minimum number of similar items that has to be bought to make a recommendation, write a program that returns the number of items bought together such that the frequency of each item is greater than or equal to k.
In the test case for the input: abbbccxypgggghhll 2, gggghhll are the 8 items brought together such that frequency of each item, i.e, frequency of item g, item h and item l are greater than or equal to 2.

Input Format

len - length of string
str - string
k - the minimum number of similar items that has to be bought to make a recommendation

Output Format

n - integer

Testcase 1
Input

6 
xyxyyz 
2
Output

5
Testcase 2
Input

17
abbbccxypgggghhll
2
Output

8 */

// Code------>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check()
{
    char s[1000],temp=1,ch='*';  
    int  i,j,k=0,n;
    int p,q;
    scanf("%d\n",&p);
    scanf("%s",s);
    scanf("%d\n",&q);
    char a[1000];
    for(int k=0;k<=p-1;k++)
    {
        a[k]=s[k];
    }
    for(i=0;s[i];i++)
    {
    	if(!(s[i]==ch))
    	{
    		for(j=i+1;s[j];j++)
            {
            	if(s[i]==s[j])
             	   s[j]=ch;
		    }
		}
    }
    for(i=0;s[i];i++)
    {
    s[i]=s[i+k];
    if(s[i]==ch)
    {
	    k++;
	    i--;
	}	
    }
    int q1=0;
    for(int i=0;i<=strlen(s)-1;i++){
        int d=0;
        int h=s[i];
        for(int j=0;j<=strlen(a)-1;j++){
            int k=a[j];
            if(k==h){
                d++;
            }
        }
        if(d>=q){
            q1=q1+d;
        }
    }
    return q1;
}
int main()
{
    int j=check();
    printf("%d",j);
}
