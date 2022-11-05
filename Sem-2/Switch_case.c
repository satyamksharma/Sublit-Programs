/*
Write a program to create a simple calculator

Input Format

A & B are operands and C is an operator

Output Format

R is the result after the computation.*/
#include<stdio.h>
int main(){
    char op;
    float a, b, r;
    scanf("%f %f %c", &a, &b, &op);
    switch(op)
    {
        case '+': r = a+b;
        break;
        case '-': r = a-b;
        break;
        case '*': r = a*b;
        break;
        case '/': r = a/b;
        break;
    }
    printf("%.1f", r);
}