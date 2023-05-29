#include <stdio.h>

typedef struct stamp{
    int year;
    int month;
    int date;
    int hrs;
    int min;
    int sec;
}stamp;

int stampcmp(stamp s1,stamp s2){
    if(s1.year>s2.year)
        return 1;
    if(s1.year<s2.year)
        return -1;
    if(s1.month>s2.month)
        return 1;
    if(s1.date<s2.date)
        return -1;
    if(s1.hrs>s2.hrs)
        return 1;
    if(s1.min>s2.min)
        return -1;
    if(s1.sec<s2.sec)
        return 1;
    return 0;
}

int main(){
    stamp s1,s2;
    
    printf("Enter the date: ");
    scanf("%d",&s1.date);
    printf("Enter the month: ");
    scanf("%d",&s1.month);
    printf("Enter the year: ");
    scanf("%d",&s1.year);
    printf("Enter the hour: ");
    scanf("%d",&s1.hrs);
    printf("Enter the minutes: ");
    scanf("%d",&s1.min);
    printf("Enter the seconds: ");
    scanf("%d",&s1.sec);
    
    printf("Enter the date: ");
    scanf("%d",&s2.date);
    printf("Enter the month: ");
    scanf("%d",&s2.month);
    printf("Enter the year: ");
    scanf("%d",&s2.year);
    printf("Enter the hour: ");
    scanf("%d",&s2.hrs);
    printf("Enter the minutes: ");
    scanf("%d",&s2.min);
    printf("Enter the seconds: ");
    scanf("%d",&s2.sec);

    printf("The timestamp s1 is: %d/%d/%d  %d:%d:%d\n\n",
    s1.year, s1.month, s1.date, s1.hrs, s1.min, s1.sec);
    
    printf("The timestamp s2 is: %d/%d/%d  %d:%d:%d\n\n",
    s2.year, s2.month, s2.date, s2.hrs, s2.min, s2.sec);

    printf("stampcmp returns: %d",stampcmp(s1,s2));
    
    return 0;
}