#include <stdio.h>
#include <string.h>

typedef struct employee{
    int code;
    float sal;
    char name[20];
}emp;   //typedef <-- can be used to write just 'emp name' 
        //instead of 'struct employee name'

int main(){
    struct employee emp1;//<--- creates an object emp1 of datatype employee
    emp1.sal=100000.00;// ' . ' is a member operator
    // emp1.name="Varun Patel" <--- Will not work as string 
    // can't be re-initialized as it was not declared as pointer.
    strcpy(emp1.name,"Varun Patel");
    emp1.code=101;
    
    emp varun={1,1000000,"Varun Patel"};//<--another way to initialize structures.
    
    printf("sal=%.2f\nname=%s\ncode=%d",emp1.sal,emp1.name,emp1.code);
    struct employee emp2;
    printf("\n\nEnter the name of employee: ");
    gets(emp2.name);
    printf("Enter the salary: ");
    scanf("%f",&emp2.sal);
    printf("Enter the employee code: ");
    scanf("%d",&emp2.code);
    
    return 0;
}