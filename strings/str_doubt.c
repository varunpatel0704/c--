#include <stdio.h>
#include <string.h>
int main(){
    char str[10]="Varun Patel";;
    //str="varun patel";//<-- A string can only be 
                // reinitialized if declared as pointer.
    
    str[5]='\0';
    puts(str);
    return 0;
}