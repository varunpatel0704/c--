#include <stdio.h>
void displayfunction(int* n, int len, int ele);

int main(){
    int a,b,len;
    
    printf("How many rows do you want?");
    scanf("%d",&a);
    printf("How many coloumns do you want?");
    scanf("%d",&b);
    
    int arr[a][b];
    
    for (int i = 0; i < a; i++)
    {
       for (int j = 0; j < b; j++)
       {
            printf("Enter the value of element (%d,%d): ",i+1,j+1);
            scanf("%d",&arr[i][j]);
       }
       
    }
    // for (int i = 0; i < a ; i++)
    // {
    //     for (int j= 0; j < b; j++)
    //     {
    //         printf("The value of element (%d,%d) is: %d \n",i+1,j+1,arr[i][j]);
    //     }
        
    // }
    //len=sizeof(arr)/sizeof(int);
    displayfunction(arr,a,b);
    return 0;
}
void displayfunction(int* n, int len, int ele){
    for (int i = 0; i < len ; i++)
    {
        for (int j= 0; j <ele; j++)
        {
            printf("The value of element (%d,%d) is: %d \n",i+1,j+1,*n);
            n++;
        }
        
    }
    
}

