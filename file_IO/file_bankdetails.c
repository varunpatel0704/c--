#include <stdio.h>
int main(){
    int bal;
    char name[50];
    printf("Enter your balance: ");
    scanf("%d",&bal);
    printf("Enter your name: ");
    scanf("%s",name);
    FILE *ptr;
    ptr=fopen("bankdetails.txt","w");
    for (int i = 0; i < 2; i++)
    {
        fprintf(ptr,"%d , %s\n",bal,name);
    }
    fclose(ptr);
    return 0;
}