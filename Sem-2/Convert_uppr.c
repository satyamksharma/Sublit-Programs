/*Convert the character to uppercase 

NOTE: Do not add any prompts like "Enter a number". Directly Accept and print the results

Input Format

A  
 
A is a character in lowercase

Output Format

B

B is A converted to uppercase
*/
#include<stdio.h>

int main()
{
    char ch,c;
    scanf("%c", &ch);
    int f=(int)ch;
    if(f>=97 && f<=123)
    {
        printf("%c",(char)(f-32));
    }
    else
    {
        printf("%c",(char)(f+32));
    }
    return 0;
}