#include <stdio.h>

void printarray(int *ptr, int len){
    for(int i=0;i<len;i++){
        printf("The value of element %d is %d\n",i+1,*(ptr+i));
        //ptr++;
    }
}

void Printarray(int array[], int len){
    
    array[1]=69;//<---when pass an array to a function as argument,
                // the address of array is passed instead. So any 
                // changes made to the array inside the function 
                // will also be reflected in main. 
    
    for(int i=0;i<len;i++){
        if(i==1){
            printf("The value of element %d is %d<---The value of this element has been changed inside function\n",i+1,array[i]);
        }
        printf("The value of element %d is %d\n",i+1,array[i]);
    }
}
int main(){
    int arr[]={12,25,64,43,76};
    printf("This is printing array using pointer method:\n");
    printarray(arr,5);
    printf("This is printing array by passing array to function:\n");
    Printarray(arr,5);

    return 0;
}