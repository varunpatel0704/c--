#include <stdio.h>
int main(){
    int n;
    FILE *ptr;
    ptr=fopen("table.txt","w");
    printf("Enter the number to write multipication table: ");
    scanf("%d",&n);
    for (int i = 1; i <= 10; i++)
    {
        fprintf(ptr,"%d * %d = %d\n",n,i,n*i);
    }
    fclose(ptr);
    return 0;
}