#include <stdio.h>
int main(){
    int marks[4];
    printf("Address of 1st index%u\n",&marks[0]);
    printf("Address of 2nd index%u\n",marks+1);
    printf("Address of 3rd index%u\n",&marks[2]);
    printf("Address of 4th index%u\n",&marks[3]);
   
    for(int i=0;i<4;i++){
        printf("Enter the marks for studet %d: ",i+1);
        scanf("%d",&marks[i]);
    }
    
    
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n",marks[i]);
    }
    
    return 0;
}