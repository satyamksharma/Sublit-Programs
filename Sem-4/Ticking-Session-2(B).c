/* The IQ hypothesis

 Dr. Meredith Grey is constructing new DNA that can create highly intellectual species of human beings. DNA is represented as a sequence of chemical bases, given by characters. Return the intelligence measure as the longest chain of the chemical bases without repetition.
Memory for the string must be dynamically allocated. Do not accept any spaces or new lines while accepting the input.
 
Explanation:
In the sample test case, “xyz” is the longest succession of chemical bases without repetition.

Input Format

str_len - length of the string
str - string

Output Format

len - integer 

Testcase 1
Input

8
xyzxyzxy
Output

3 */

// Program------>
#include<stdio.h>
#include<stdlib.h>



int un(char *a,int i,int j){
    int vis[26]={};
    for(int k=i;k<=j;k++){
        if(vis[a[k]-'a']==1){
            return 0;
        }
        vis[a[k]-'a']=1;
    }
    return 1;
}


int find(char *a,int n){
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(un(a,i,j)==1){
                if(c<j-i+1){
                    c=j-i+1;
                }
            }
        }
    }
    return c;
}


int main(){
    int l;
    scanf("%d",&l);
    char a[l];
    scanf("%s",a);
    printf("%d",find(a,l));
}