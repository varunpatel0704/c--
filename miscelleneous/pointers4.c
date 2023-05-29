#include <stdio.h>
int main(){
    int x=10;
    int *ptr=&x;
    int **ptrtoptr=&ptr;

    printf("The value of x using pointer to pointer method is %d",*(*ptrtoptr));
    return 0;
}