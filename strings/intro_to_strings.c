#include <stdio.h>
int main(){
    //char str[]={'V','a','r','u','n','\0'};
    char str[]="Varun";//<---This another way of initializing strings.
    char *ptr= str;
                       //*(ptr+1)='\0';
    while(*ptr!='\0'){
        printf("%c",*ptr);
        ptr++;
    }

    return 0;
}