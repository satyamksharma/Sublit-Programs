/*Collision handling using Double Hashing

Insert values into a hash table using the hash function given below. Use double
hashing to resolve collisions i.e.,
Collisions must be handled by calculating the index value using a second hash
function by maintaining
collision count.
The hash table is of a constant size of 13. The first hash function is simply
key%table_size. The second hash function is taken as, x-(key%x). The value of x is
taken as the largest prime number less than the table size, in this case, 11. By
default all values of the hash table is 0.

Input Format

Each test case starts with a digit ‘n’, which is the number of values that have to be
inserted, followed by the n line-separated numbers that must be inserted into the
hash table.

Output Format

The printHashTable function must be implemented which prints the values of the
hash table in a space separated manner. ‘-1’ must be printed in the insertIntoHash
function if there is any insufficient space on the table. Any number of ‘-1’s will only
be printed before the printHashTable function is called.

Testcase 1
Input

10
2
4
6
8
10
12
14
16
18
20
Output

0 14 2 16 4 18 6 20 8 0 10 0 12
Testcase 2
Input

14
1
2
3
4
5
6
7
8
9
10
11
12
13
14
Output

-1
13 1 2 3 4 5 6 7 8 9 10 11 12*/
#include <stdio.h>
#include<stdlib.h>
#define SIZE 13


void insertIntoHash(int key, int *hashtable)
{
    int h2 = 11 - key % 11;
    int h1 = key % SIZE;
    int i = 0;
    while(hashtable[(h1 + i*h2)%SIZE]){
        if(i==13){
            printf("-1");
            printf("\n");
            return;
        }
        i++;
    }
    hashtable[(h1 + i*h2)%SIZE] = key;
}

void printHashTable(int *hashtable)
{
    for(int j=0;j<SIZE;j++) printf("%d ",hashtable[j]);
    printf("\n");
}

int main()
{
    int i;
    int h[SIZE]={0};

    int n;
    scanf("%d", &n);

    int stk[n];
    for(int k=0;k<n;k++){
        scanf("%d", &stk[k]);
    }

    for(int i=0;i<n;i++){
        insertIntoHash(stk[i], h);
    }

    printHashTable(h);

    return 0;
}
