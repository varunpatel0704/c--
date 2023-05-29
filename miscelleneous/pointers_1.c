#include <stdio.h>

void print_address(int x){
    printf("The address of formal parameter is: %u\n",&x);
}


int main(){
    int i;
    print_address(i);
    printf("The address of i is: %u\n",&i);
    return 0;
}