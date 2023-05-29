#include <stdio.h>
int main(){
    int a=520, b=39;
    int *ptr3=&b;
    int *ptr=&a;
    int *ptr2=&a;
    if (ptr2==ptr){
        printf("True\n");
    }

    ptr+=2;
    printf("%u\n",ptr);
    printf("%u\n",ptr2);
    printf("ptr2-ptr=%d",ptr-ptr2);
    return 0;
}