#include <stdio.h>
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int count;
    for(int i=2;i<(n/2);i++){
        if(n%i==0)
            count=1;
    }
    if(count==1)
        printf("number is not prime!");
    else
        printf("Number is prime");
    return 0;
}