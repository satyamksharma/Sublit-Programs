/*
Problem solving 2

You find N coins, where each coin is associated with a value and a weight. These are given in the arrays V and WT. You have a bag that can hold a total weight of W. Find out the maximum value of coins you can fit in the bag without exceeding the weight capacity of the bag. You are not allowed to split a coin or take fractions of a coin, you must either pick a coin or leave it out of the bag

Input Format

3		// number of coins
1 2 3	// array V
4 5 3	// array WT
4		// total weight W

Output Format

3 

Testcase 1
Input

3
1 2 3
4 5 6
4 
Output

1

*/
//Code -- only 3/4 TC's passed
#include<stdio.h>

int max(int a, int b)
{
    return (a > b)? a : b;
}

int kps(int W, int wt[], int val[], int num)
{
    if (num == 0 || W == 0)
        return 0;
 
    if (wt[num-1] > W)
        return kps(W, wt, val, num-1);
 
    else return max( val[num-1] + kps(W-wt[num-1], wt, val, num-1),
                    kps(W, wt, val, num-1)
                  );
}

int main()
{
    int num;
    scanf("%d",&num);
    int val[num];
    int wt[num];

    for(int i=0;i<num;i++){
        scanf("%d",&val[i]);
    }
    for(int j=0;j<num;j++){
        scanf("%d",&wt[j]);
    }
    int  W;
    scanf("%d",&W);
    printf("%d", kps(W, wt, val, num));
    return 0;
}

