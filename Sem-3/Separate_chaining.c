/*Insert values into a hash table using the hash function given below.
Use separate chaining to resolve the collision i.e., handle collisions must
by appending the collided values to the end of the linked list at its respective index.

Input Format

Each test case starts with a digit ‘s’, which represents the size of the hash table
created.
The next input is a digit ‘n’, which is the number of values that have to be inserted,
followed by the n line-separated numbers that must be inserted into the hash table.

Output Format

For this problem the display function has been handled in the boilerplate code as
output formats could become unnecessarily confusing.

Testcase 1
Input

5
10
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
Output

[0]->5->10->NULL
[1]->1->6->NULL
[2]->2->7->NULL
[3]->3->8->NULL
[4]->4->9->NULL
Testcase 2
Input

3
2
6
8
Output

[0]->6->NULL
[1]->NULL
[2]->8->NULL*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node  *next;
}NODE;

NODE* create(int data)
{
    NODE *temp =   malloc(sizeof(NODE));
    temp->data  =data;
    temp->next=NULL;
    return temp;
}

void insertIntoHash(int size, int value, struct node** chain)
{
    int key = value%size;
    NODE *new = create(value);
    if(!chain[key])
        chain[key] = new ;
    else{
        NODE *curr = chain[key];
        while(curr->next)
            curr = curr->next;
        curr->next = new;
    }
}

void  print( int size,  struct node** chain){
    for(int  i = 0;  i < size;  i++){
        struct node *temp = chain[i];
        printf("[%d]",i);
        while(temp){
            printf("->%d", temp->data)  ;
            temp = temp->next;
        }
        printf(  "->NULL\n")  ;
    }
}

void createHash(int size, int stk[], int n, struct node** chain){
    for(int i=0;i<n;i++){
        insertIntoHash (size, stk[i], chain);
    }
}

int main(){
    int i;
    int size;
    scanf("%d", &size);

     struct node *chain[size];

    for(i = 0; i < size; i++){
        chain[i] = NULL  ;
    }

    int    n;
    scanf  (  "%d", &n)  ;

    int    stk[n];
    for  (int k=0;  k<n;  k++){
        scanf  ("%d", &stk[k])  ;
    }

    createHash( size, stk, n, chain);
    print(size, chain);

    return 0;
}