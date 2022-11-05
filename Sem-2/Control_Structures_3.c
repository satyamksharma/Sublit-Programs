/*Write a Program to convert all characters in a given line from lower case to upper
case.

Input Format

S
Where S is a string with lower and uppercase characters 

Output Format

S' 
Where S' is S with all characters converted to Uppercase

*/
#include<stdio.h>
int main()
{
    char c;
    while((c=getchar())!=EOF)
    {
        if(c>='a' && c<='z')
        {
            c=c-'a'+'A';
        }
        putchar(c);
    }
    return 0;
}