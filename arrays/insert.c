#include <stdio.h>
int main(){
    int a[15],n,i,pos;
    printf("Enter the number of elements to be entered: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the element: ");
        scanf("%d",&a[i]);
    }
    printf("At which position do you want to insert the element?");
    scanf("%d",&pos);
    for(i=n;i>pos;i--){
        a[i+1]=a[i];
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&a[pos]);
    printf("The updated array is: ");
    for ( i = 0; i < n+1; i++)
    {
        printf("%d ,", a[i]);
    }
    

    return 0;
}