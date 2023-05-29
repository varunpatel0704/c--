#include <stdio.h>

void encrypt(char str[]){
    int i=0;
    while (str[i]!='\0')
    {
        str[i]+=1;
        i++;
    }
    
}
void decrypt(char str[]){
    int i=0;
    while (str[i]!='\0')
    {
        str[i]-=1;
        i++;
    }
    
}
int main(){
    char str[50];
    printf("Enter the string to encrypt: ");
    gets(str);
    encrypt(str);
    printf("The encrypted string is: %s", str);
    decrypt(str);
    printf("\nThe decrypted string is: %s", str);
    return 0;
}