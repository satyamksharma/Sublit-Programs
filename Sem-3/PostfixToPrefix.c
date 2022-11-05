/*A Prefix expression, is a mathematical notation in which operators precede their
operands, in contrast to the more common infix expression, in which operators are placed
between operands.

Prefix/postfix notation is especially popular for its innate ability to express the
intended order of operations without the need for parentheses and other precedence rules,
as are usually employed with infix notation. That is why the calculators we use may internally
be using prefix expressions to evaluate your input expression.

In this week’s lab exercise you will need to write functions for the following:
1. Given an infix expression “infix_exp” of length n, convert it to an prefix
expression “prefix_exp”
2. Given a prefix expression “prefix_exp”, evaluate it to get an integer result.

Your task is to complete 2 functions:
Void infix_to_prefix(char infix[SIZE], char prefix[SIZE], int n); // store the prefix
expression in the string prefix
int evaluatePrefix(char prefix[SIZE], int n); // returns evaluation result of prefix

Consider the following order for operator precedence:
1. ^
2. /, *
3. +, -

You are free to use the boilerplate code mailed to you or you can write one abiding
the input and output format provided below. Do not keep unnecessary print statements.

Use appropriate data structure(s) and complete the task such that your code should
be complete, meaning it should be able to give the right output for any valid input, handling
all the edge cases.

Input Format

Each test case will have 1 line as input.
The line contains an integer n and a string(character array) “infix_exp” of size n with
a space separating them.
1 <= n <= 100
Each character in infix_exp will be either 0-9 or one of ^, /, +, -, ) or (
Each input will always be vaild. No need to check if input it invalid.

Output Format

The output should:
1. The equivalent prefix expression which is a string(character array)
2. The evaluation result after processing the prefix expression.

These both need to be outputted after separating with a space*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct Node
{
    char data;
    struct Node *next;
} NODE;

typedef struct Stack
{
    NODE *top;
} STACK;

NODE *createNode(char);
STACK *createStack();
void push(STACK *, char);
NODE *pop(STACK *);
char peek(STACK *);
void displayStack(STACK *);
int findPrio(char);
void prioPush(STACK *, char, STACK *);
int power(int, int);
void infixToPostfix(char[], char[], int);
int evaluatePrefix(char[], int);

NODE *createNode(char data)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    return node;
}

STACK *createStack()
{
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    stack->top = NULL;
    return stack;
}

void push(STACK *stack, char data)
{

    if (stack->top == NULL)
        stack->top = createNode(data);
    else
    {
        NODE *new = createNode(data);
        new->next = stack->top;
        stack->top = new;
    }
}

NODE *pop(STACK *stack)
{
    if (stack->top == NULL)
    {
        return NULL;
    }
    else
    {
        NODE *temp = stack->top;
        stack->top = stack->top->next;
        char data = temp->data;
        free(temp);
        return (createNode(data));
    }
}

char peek(STACK *stack)
{
    if (stack->top)
        return (stack->top->data);
    else
        return '\0';
}

int findPrio(char operand)
{
    int priority = -1;
    switch (operand)
    {
    case '(':
        priority = 4;
        break;
    case '^':
        priority = 3;
        break;
    case '*':
    case '/':
    case '%':
        priority = 2;
        break;
    case '+':
    case '-':
        priority = 1;
        break;
    case ')':
        priority = 0;
        break;
    }
    return priority;
}

void prioPush(STACK *stack, char operand, STACK *temp)
{
    if (operand == '(')
    {
        NODE *popped = pop(stack);
        while (popped->data != ')')
        {
            push(temp, popped->data);
            popped = pop(stack);
        }
    }
    else
    {
        while (findPrio(peek(stack)) > findPrio(operand))
        {
            push(temp, pop(stack)->data);
        }
        push(stack, operand);
    }
}

int power(int a, int b)
{
    int ans = 1;
    for (int i = 1; i <= b; i++)
        ans *= a;
    return ans;
}

void infixToPostfix(char infix[SIZE], char prefix[SIZE], int n)
{

    STACK *stack = createStack();
    STACK *final = createStack();

    for (int i = 0; i < n; i++)
    {
        if (infix[i] != '\0')
            push(stack, infix[i]);
    }

    NODE *popped = pop(stack);
    int i = 0;

    while (popped != NULL)
    {
        infix[i] = popped->data;
        popped = pop(stack);
        i++;
    }

    // printf("the reversed string is %s\n\n", infix);

    for (int i = 0; i < n; i++)
    {
        switch (infix[i])
        {
        case ' ':
        case '\0':
        case '\n':
            break;
        case ')':
            push(stack, infix[i]);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '(':
        case '^':
            prioPush(stack, infix[i], final);
            break;
        default:
            push(final, infix[i]);
            break;
        }
    }

    int is_empty = 0;

    if (peek(stack) == '\0')
    {
        is_empty = 1;
    }

    while (!is_empty)
    {
        push(final, pop(stack)->data);
        if (peek(stack) == '\0')
            is_empty = 1;
    }

    int j = 0;
    while (final->top)
    {
        prefix[j] = pop(final)->data;
        j++;
    }
    prefix[j] = '\0';
}

int evaluatePrefix(char prefix[SIZE], int n)
{

    STACK *stack = createStack();
    int n1 = 0, n2 = 0;
    for (int i = n; i >= 0; i--)
    {
        if ((prefix[i] >= '0') && (prefix[i] <= '9'))
        {
            push(stack, (long long int)(prefix[i] - 48));
        }
        else
        {
            switch (prefix[i])
            {
            case '+':
                n1 = pop(stack)->data;
                n2 = pop(stack)->data;
                push(stack, n1 + n2);
                break;
            case '-':
                n1 = pop(stack)->data;
                n2 = pop(stack)->data;
                push(stack, n1 - n2);
                break;
            case '*':
                n1 = pop(stack)->data;
                n2 = pop(stack)->data;
                push(stack, n1 * n2);
                break;
            case '/':
                n1 = pop(stack)->data;
                n2 = pop(stack)->data;
                push(stack, n1 / n2);
                break;
            case '%':
                n1 = pop(stack)->data;
                n2 = pop(stack)->data;
                push(stack, n1 % n2);
                break;
            case '^':
                n1 = pop(stack)->data;
                n2 = pop(stack)->data;
                push(stack, power(n1, n2));
                break;
            }
        }
    }
    return pop(stack)->data;
}

int main()
{
    char infix[SIZE], prefix[SIZE];
    int n;
    scanf("%d", &n);
    scanf("%s", infix);
    infixToPostfix(infix, prefix, n);
    int res = evaluatePrefix(prefix, strlen(prefix));
    printf("%s %d\n", prefix, res);

    return 0;
}