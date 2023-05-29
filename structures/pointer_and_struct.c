#include <stdio.h>
#include <string.h>
struct employee{
    int code;
    float sal;
    char name[20];
};
int main(){
    struct employee emp;
    struct employee *ptr;
    ptr=&emp;
    (*ptr).code=101; //<--"(*ptr).code" can also be written as "ptr->code", "->" is the arrow operator.
    strcpy((*ptr).name,"Varun Patel");
    ptr->sal=1000000;
    printf("%d\n",emp.code);
    printf("%s\n",emp.name);
    printf("%.2f",emp.sal);
    

    
    return 0;
}