#include <stdio.h>
int main(){
    int num,num2;
    FILE *ptr;
    ptr=fopen("sample.txt","r");
    
    fscanf(ptr,"%d",&num);//<---this will read 
                          //the first int encountered in the file
    printf("The value of num is: %d\n",num);
    for (int i = 0; i < 8; i++)
    {
        fscanf(ptr,"%d",&num2);//<---this will read 
                          //the next int encountered in the file
        printf("The value of num2 is: %d\n",num2);
    }
    
    fclose(ptr);
    
    
    return 0;
}