/*
Problem solving 3

6. You are given a matrix with n rows and m columns. Each cell can be of three types:
Empty, denoted by '.'
A stone, denoted by '*', falls downwards
An obstacle, denoted by ‘o’, always stationary
All the stones fall down until they either meet an obstacle, another immovable stone, or the floor, i.e the bottom row.
What will the resultant grid look like after all stones are stationary?




Input Format

4 4			// n rows and m columns
.*..			// input matrix
.*.*
oo..
.... 

Output Format

.*..			// output matrix
.*..
oo..
...* 

Testcase 1
Input

2 9
...***ooo
.*o.*o.*o 
Output

....**ooo
.*o**o.*o 

*/

//Solution 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){

int n, m;
    scanf("%d %d", &n, &m);
    char word[n][m];
    for(int i = 0;i<n;i++)
    {
        char inp[m];
        scanf("%s",inp);
        for(int j = 0;j<m;j++)  //m is length of each string
        {
            word[i][j] = inp[j];
        }
    }
 int p = 1;
    while(p == 1)
    {
        int count_x=0;
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j<m;j++)  
        {
            if(word[i][j]=='*' && word[i+1][j]=='.')
            {
               word[i+1][j]='*';
               word[i][j]='.';
               count_x++;
            }
            
        }
    }
     if(count_x == 0)
        {
            p = 0;
        }
    }
    



    //Print fun for final o/p
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",word[i][j]);
        }
        printf("\n");
    }
}