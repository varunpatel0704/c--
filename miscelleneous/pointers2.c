#include <stdio.h>
void multiplier(int* a){     
    (*a)*=10;
}

int Multiplier(int a){      //<--call by reference
    return a*10;
}

int main(){
    int i,j;
    
    printf("Enter the value of i: ");
    scanf("%d",&i);
    multiplier(&i);
    printf("The new value of i is : %d\n",i);
    
    printf("Enter the value of j: ");
    scanf("%d",&j);
    printf("The new value of j is : %d\n",Multiplier(j));
    
    return 0;
}