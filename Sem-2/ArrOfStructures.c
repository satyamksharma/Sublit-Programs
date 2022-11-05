/*Define a structure called cricket that will describe the following information:

player name
team name
batting average

Using cricket, declare an array of players with 5 elements and write a program to read the information about all the 5 players, and print a team-wise list containing the names of players with their batting average. Write functions for the following:

i) Read the information of all the 5 players
ii)Sorting the players
iii)Displaying a team-wise list containing names of player with their batting average

Input Format

N-No of Players
PN-TN,BA - Player Name, Team Name, batting Average

Output Format

After Team-wise Sorting, the Player list is :
PN-TN'-BA
so on....

*/
#include <stdio.h>
#include <string.h>

struct cricket
{
    char pname[20];
    char tname[20];
    int bavg;

};
int main()
{
    struct cricket s[5],t;
    int i,j,n;
    int p;
    scanf("%d",&n);
    

    
    for(i=0;i<n;i++)
    {
    
        scanf("%s %s %d",s[i].pname,s[i].tname,&p);
        s[i].bavg=p;


    }
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if(strcmp(s[j-1].tname,s[j].tname)>0)
            {
                t=s[j-1];
                s[j-1]=s[j];
                s[j]=t;
            }
        }
    }
for(i=0;i<n;i++)
{
    printf("%s %s %d\n",s[i].pname,s[i].tname,s[i].bavg);
}

return 0;
}