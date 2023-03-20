/*
The Comprehensive Guide to Language Mastery

You are a language expert who has been hired by a group of aliens who are trying to learn human language. They are having trouble understanding the concept of vowels, and want to study them more closely. They've asked you to write a program that will take a string and invert the order of the vowels. The aliens want to use this program to better understand how vowels are used in the English language.

Input Format

n - length of string
str - string

Output Format

vow_str - string

Testcase 1
Input

10
algorithms
Output

ilgorathms
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
int vowelCheck(char c)
{
    return (c=='a' || c=='A' || c=='e' ||
            c=='E' || c=='i' || c=='I' ||
            c=='o' || c=='O' || c=='u' ||
            c=='U');
}

int main()
{
    int n;
    char str[100];
    scanf("%d", &n);
    scanf("%s", &str);

    int j=0;
    char vowel[100];
    for (int i=0; str[i]!='\0'; i++)
        if (vowelCheck(str[i]))
            vowel[j++] = str[i];
 
    for (int i=0; str[i]!='\0'; i++)
        if (vowelCheck(str[i]))
            str[i] = vowel[--j] ;
 
    printf("%s", str);
    return 0;
}
