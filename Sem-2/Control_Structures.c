/*
Write a program to calculate the grade of the student according to the specified marks.
Grade A:Marks(>85 and <=100)
Grade B:Marks(>60 and <=85)
Grade C:Marks(>40 and <=60)
Grade D:Marks(>30 and <=40)
Fail: Marks(<30)

Input Format

Marks  between the range of values as specified:
55

Output Format

Grade : 
C
*/

#include<stdio.h>

int main()
{
    int marks;
    scanf("%d", &marks);
    if(marks<0 || marks >100)
    {
        printf("Wrong Input");
    }
    else if(marks>85 && marks<=100)
    {
        printf("A");
    }
    else if(marks>60 && marks<=85)
    {
        printf("B");
    }
    else if(marks>40 && marks<=660)
    {
        printf("C");
    }
    else if(marks>30 && marks<=40)
    {
        printf("D");
    }else
    {
        printf("Fail");
    }
    return 0;
}
