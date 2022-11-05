/*Write a function to find all occurrences of a character in a string and use this function to replace all occurrences of a character by a specific character.

Input Format

S = Input String
C= Character to replace
C'= Character replaced with C

Output Format

R: Resultant after replacing*/
#include<stdio.h>
#include<string.h>

void replaceChar(char *c, char c1, char c2){
    int i=0;
    for(i=0;c[i];i++){
        {
            if(c[i]==c1)
                c[i]=c2;

        }
    }
}
void main(){
    char s[100],c1,c2;
    gets(s);
    c1=getchar();
    getchar();
    c2=getchar();
    replaceChar(s,c1,c2);
    puts(s);
    
}