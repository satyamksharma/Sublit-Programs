/*Write a function to Concatenate two strings and use this to concatenate n (i.e, say 2) strings.
Note: DO NOT USE STRCAT() OR ANY INBUILT FUNCTIONS

Input Format

s1: 1st String
s2: 2nd String
N: No of times to append

Output Format

N': String after concatenation*/
#include<stdio.h>
int main(){
    char s1[100],s2[100],s3[100];
    int i=0,j=0,x;
    gets(s1);
    gets(s2);
    scanf("%d",&x);
    while(s1[i]!='\0')
    {
        s3[j]=s1[i];
        i++;
        j++;
    }
    for(int k=0;k<x;k++)
    {
        i=0;
        while(s2[i]!='\0')
        {
            s3[j]=s2[i];
            j++;
            i++;
        }

    }
    s3[j]='\0';
    printf("%s", s3);
}

