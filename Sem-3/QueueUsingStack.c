/*A queue is defined as a linear data structure that is open at both ends and the operations are performed in First In First Out (FIFO) order.

We define a queue to be a list in which all additions to the list are made at the rear end, and all deletions/retrievals from the list are made at the front end. This abstract data type follows a First In First Out (FIFO) order where the operations are first performed on the elements which are inserted first into the data structure.

Your task is to implement a First In First Out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (enqueue, dequeue, peek, and empty).

You are required to implement the following queue operations as a part of this lab exercise:

1) void enqueue(MyQueue *q, int x)
This function inserts an element x to the end of the queue.

2) int dequeue(MyQueue *q)
This function returns the element at the front of the queue and removes that element from the queue. It returns -1 if the queue is empty.

3) int peek(MyQueue *q)
This operation returns the element at the front of the queue. It returns -1 if the queue is empty.

4) bool empty(MyQueue  *q)
This operation returns true if the queue is empty, else returns false.

You are supposed to use the two stacks provided to you via the boilerplate code.
These stacks are provided to you in the form of two integer arrays and their respective top variables enclosed in a structure. 

/* 
typedef struct {
    int stack1[MAXSIZE];
    int stack2[MAXSIZE];
    int top1;
    int top2;
} MyQueue;

The top of the stack is initialised to -1, indicating the stack is empty. 
In order to perform the PUSH operation, we just pre increment the TOP variable and store the intended element in that particular position in the stack. 
Similarly for performing the POP operation, we retrieve the element present in the TOP position and simply post decrement it. 

Check out this (https://tinyurl.com/stack-example) image for a better clarity.

The stacks provided as a part of the MyQueue structure can be accessed in the following way:
/*
int topElement(MyQueue *q){
    return q->stack1[q->top1];
}

int topPosition(MyQueue *q){
    return q->top1;
}


Note: 
You are required to use the stack1 for inserting an element onto the queue. 
The stack2 should only be used as an auxiliary stack and remain empty at all times. 
The validate operation provided as a part of the boilerplate checks for the validity of both the stacks. 
So MAKE SURE to use the expected implementation of the problem and not a workaround of the same. 

USING THE BOILERPLATE CODE PROVIDED BY US IS MANDATORY.
YOU WILL FAIL MOST OF THE TEST CASES IN CASE YOU FAIL TO DO SO.

Input Format

Each test case starts with a digit ‘n’, followed by n operations on the queue. 

The four operations of the queue are denoted with a letter each given below:
1) E (enqueue):
You need to enqueue the integer following E onto the rear end of the queue. 
This operation prints 1 upon successful enqueue.

2) D (dequeue): 
You need to return the integer at the front end of the queue and remove it from the queue.
This operation prints the dequeued element. It returns -1 if the queue is empty.

3) V (validate): 
This operation has already been implemented as a part of the boilerplate.
This operation pops ‘x’ elements from stack1 where ‘x’ is an integer followed by ‘V’. It returns the element present in the stack after ‘x’ pops. If the stack goes empty at any point of time, it just returns -1.
This operation also checks if the stack2 is empty.
The stack remains intact after the validate operation is performed.

4) P (peek): 
This operation returns the element present at the front end of the queue. It returns -1 if the queue is empty.

Output Format

You don’t need to print anything as a part of this lab exercise. 
Make sure to remove all the printfs and scanfs used for debugging. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 20
int count = 0;
typedef struct
{
    int stack1[MAXSIZE];
    int stack2[MAXSIZE];
    int top1;            
    int top2;   
} MyQueue;

void enqueue(MyQueue *q, int x)
{
    q->top1++;
    q->stack1[q->top1] = x;
    count++;
}
int dequeue(MyQueue *q)
{
    if (q->top1 == -1 && q->top2 == -1)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {

            int temp = q->stack1[q->top1--];
            q->top2++;
            q->stack2[q->top2] = temp;
        }
        int x = q->stack2[q->top2];
        q->top2--;
        
        count--;
        for (int i = 0; i < count; i++)
        {

            int temp = q->stack2[q->top2--];
            q->top1++;
            q->stack1[q->top1] = temp;
        }
        return x;
    }
}
int peek(MyQueue *q)
{
    if (q->top1 != -1)
    {
        return q->stack1[0];
    }
    else
    {
        return -1;
    }
}
bool empty(MyQueue *q) {
    if(q->top2==-1 && q->top1==-1)
    return true;
    else
    return false;
}
int validate(MyQueue *q, int pops)
{
    if (q->top2 != -1 || q->top1 < pops)
    {
        return -1;
    }

    int x = pops, ele = -1;
    while (x > 0 && q->top1 != -1)
    {
        q->stack2[++q->top2] = q->stack1[q->top1--];
        x--;
    }

    if (q->top1 != -1)
    {
        ele = q->stack1[q->top1];
    }

    x = pops;
    while (x > 0 && q->top2 != -1)
    {
        q->stack1[++q->top1] = q->stack2[q->top2--];
        x--;
    }

    return ele;
}
int main()
{
    MyQueue q;
    q.top1 = -1;
    q.top2 = -1;
    int no_of_operations;
    scanf("%d", &no_of_operations);
    int ele, correct_ele, no_of_pops;
    char operation;

    for (int i = 0; i < no_of_operations; i++)
    {
        scanf(" %c", &operation);
        switch (operation)
        {
        case 'E':
            scanf("%d", &ele);
            enqueue(&q, ele);
            printf("1 ");
            break;
        case 'D':
            ele=dequeue(&q);
            printf("%d ",ele);
            break;
        case 'P':
            ele = peek(&q);
            printf("%d ", ele);
            break;
        case 'V':
            scanf("%d", &no_of_pops);
            printf("%d ", validate(&q, no_of_pops));
            break;
        }
    }
    return 0;
}