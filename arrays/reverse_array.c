#include <stdio.h>

int count_pstv(int *ptr, int z){
    int count=0;
    for (int i = 0; i < z; i++)
    {
        if(*ptr>0){
            count++;
        }
        ptr++;
    }
    
    return count;
}

void reverse(int arr[], int n){
    int temp;
    for (int x = 0; x < n/2; x++)
    {
        temp=arr[x];
        arr[x]=arr[n-x-1];
        arr[n-x-1]=temp;
    }
    
}

int main(){
    int array[7]={1,-2,3,4,-5,6,-7};
    printf("The og array is: ");
    for(int i=0;i<7;i++){
        printf("%d ",array[i]);
    }
    reverse(array,7);
    printf("\nThe reversed array is:");
    for (int b = 0; b < 7; b++)
    {
        printf("%d ",array[b]);
    }

    printf("\nThe number of +ve integers in the array is: %d"
    ,count_pstv(array,7));
    
    return 0;
}