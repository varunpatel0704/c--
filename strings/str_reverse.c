#include <stdio.h>
#include <string.h>
int main(){
    int i;
    char str1[20], str2[20];
    printf("Enter the string: ");
    gets(str1);
    int length=strlen(str1);
    printf("%d", length);
    for(i=0;i<length;i++){
        str2[i]=str1[length-i-1];
    }
    str2[i]='\0';
    printf("The original string is: %s\n\n", str1);
    printf("The reversed string is: %s", str2);

    return 0;
}