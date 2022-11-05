/*Write a program to validate a given date and find the next date

Input Format

The date is provided in the format of DD-MM-YYYY

Output Format

Print the next date in the same format

*/
#include<stdio.h>
int main()
{
    int dd,mm,yy,max1;
    scanf("%d-%d-%d",&dd,&mm,&yy);
    if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12){
        max1=31;
    }
    else if(mm==4 || mm==6 || mm==9 || mm==11){
        max1=30;
    }
    else if(yy%4==0 && yy%100!=0 || yy%400==0){
        max1=29;
    }
    else{
        max1=28;
    }
    if(mm<1 || mm>12){
        printf("Month is invalid");
    }
    else if(dd<1 || dd>max1){
        printf("Date is invalid");
    }
    else if(dd==max1 && mm!=12)
    {
        dd=1;
        mm=mm+1;
        printf("%02d-%02d-%02d",dd ,mm,yy);
    }
    else if(dd==31 && mm==12)
    {
        dd=1;
        mm=1;
        yy=yy+1;
        printf("%02d-%02d-%02d",dd ,mm,yy);
    }
    else
    {
        dd=dd+1;
        printf("%02d-%02d-%02d",dd ,mm,yy);
    }
    return 0;
}