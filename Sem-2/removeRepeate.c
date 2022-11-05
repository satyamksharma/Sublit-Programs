/*Write a function to remove all repeated characters from a given string and display the string without duplicate characters.

Input Format

s- input string

Output Format

s' - output string after removing duplicates

*/
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i,j,k;
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
        for(j=i+1; str[j]!='\0'; j++)
        {
            if(str[j]==str[i])
            {
                for(k=j; str[k]!='\0'; k++)
                {
                    str[k]=str[k+1];
                }
            }
        }
    }
    printf("%s", str);
    return 0;
}

