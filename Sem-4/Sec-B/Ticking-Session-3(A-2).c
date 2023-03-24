/*
There are N people in a room standing in a circle, and each person is represented by an index from [1, N]. You go around the circle, starting from index 1, skipping a fixed number of K-1 (where K > 0) people, and execute the next, i.e, the Kth person. After every execution, the number of people in the circle gets smaller and smaller. In the end, only one person survives. Find the person in the circle that survives.

Input Format


Sample input:
7 3				// N and K


Output Format

Sample output:
4				// index of the final survivor

*/

#include<stdio.h>
int jos(int n,int k)
{
    if (n == 1) {
        return 1;
    } else {
        return (jos(n - 1, k) + k-1) % n + 1;
    }
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d",jos(n,k));
}
