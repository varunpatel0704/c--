#include <stdio.h>
#include <string.h>
int strcustomlen(char *st){
    int len=0;
    
    while(*st!='\0'){
        len++;
        st++;
    }
    return len;
}
char* customcpy(char * target, char * source){
    int i=0;
    while(source[i]!='\0'){
        target[i]=source[i];
        i++;
    }
    target[i]='\0';
    return target;

}
char *my_strcpy(char *destination, char *source)
{
    char *start = destination;//<----saves the base address of array

    while(*source != '\0')
    {
        *destination = *source;
        destination++;  //<-----original address is lost
        source++;
    }

    *destination = '\0';
    return start;//<--- returns original base address 
}
int main(){
    char str1[50]="Hello";
    char str2[50]="world";
    strcpy(str2, str1);//<---strcpy(target,source);....str1 will be copied 
                       //    and pasted to str2.
    puts(str2);
    strcat(str1, str2);//<--- concatinates str2 behind str1.
    puts(str1);
    printf("comparing str1 and str2: %d",strcmp(str1,str2));
    printf("\nlength of str1 is : %d",strlen(str2));
    printf("\nlength of str2 is %d",strcustomlen(str2));
    customcpy(str1,str2);
    my_strcpy(str2, str1);
    puts(str1);
    puts(str2);
    return 0;
}