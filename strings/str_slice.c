#include <stdio.h>
int main(){
    char str[100];
    printf("Enter the string: ");
    gets(str);
    int i=0, start, stop;
    printf("Enter the start and stop values: ");
    scanf("%d%d", &start, &stop);
    while(start<stop){
        str[i]=str[start-1];
        i++;
        start++;
    }
    str[i]='\0';
    printf("sliced string is: %s", str);
    return 0;
}