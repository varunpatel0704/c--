#include <stdio.h>
#include <string.h>

typedef struct bank_account{
    int accno;
    char name[20];
    char date[9];
    float bal;
}bank;

int main(){
    bank b1;
    b1.accno=123456789;
    strcpy(b1.name,"Varun Patel");
    strcpy(b1.date,"07/04/03");
    b1.bal=1067390.32;
    printf("%d\n",b1.accno);
    puts(b1.name);
    printf("%f\n",b1.bal);
    printf("%s\n",b1.date);
    return 0;
}