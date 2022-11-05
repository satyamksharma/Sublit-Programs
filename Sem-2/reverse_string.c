/*Write a function to reverse a given string

Input Format

S: Input String

Output Format

S': Reversed String

*/
#include<stdio.h>
#include<string.h>

void reverse(char mystr[50], int n);
void main(){
    char mystr[50];
    int len;
    gets(mystr);
    len=strlen(mystr);
    reverse(mystr, len);    
}

void reverse(char mystr[50], int n)
{
    for(int i=n-1; i>=0; i--)
        printf("%c", mystr[i]);
}