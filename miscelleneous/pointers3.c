#include <stdio.h>

void operations(int a, int  b, float *sum, float *avg){
    *sum=(a)+(b);
    *avg=(*sum/2.0);
}

int main(){
    float i,j,sum,avg;/*<-- created avg and sum and will 
    pass their address to void function and change 
    their values without using return keyword.*/
    
    printf("Enter the value of j: ");
    scanf("%f",&i);
    printf("Enter the value of j: ");
    scanf("%f",&j);
    operations(i,j,&sum,&avg);
    printf("The sum and average of the two numbers is %0.2f and %0.2f respetively\n",sum,avg);
    
    return 0;
}