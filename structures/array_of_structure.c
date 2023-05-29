#include <stdio.h>
#include <string.h>
struct employee{
    int code;
    float sal;
    char name[20];
}; 
int main(){
    struct employee facebook[100];//an array of objects can be created to store large number elements
    strcpy(facebook[0].name,"Varun Patel");
    facebook[0].code=1;
    facebook[0].sal=100.54;
    printf("\nName: %s",facebook[0].name);
    printf("\nCode: %d",facebook[0].code);
    printf("\nSalary: %.2f",facebook[0].sal);

    return 0;
}