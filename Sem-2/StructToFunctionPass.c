/*Write a C Program to Add  two Complex Numbers by Passing Structure to a Function

Input Format

R & I are real & imaginary part of Complex no 1
R' & I' are real & imaginary part of Complex no 2

Output Format

Sum of Complex nos*/
#include<stdio.h>
typedef struct complex{
    float real;
    float imag;
}complex;

complex add(complex n1, complex n2);

 int main()
 {
     complex n1, n2, sum;
     scanf("%f%f",&n1.real ,&n1.imag);
     scanf("%f%f",&n2.real ,&n2.imag);
     sum = add(n1, n2);
     printf("%.1f+%.1fi\n", sum.real, sum.imag);
 }
 complex add(complex n1, complex n2)
 {
     complex temp;
     temp.real = n1.real + n2.real;
     temp.imag = n1.imag + n2.imag;
     return temp;
 }