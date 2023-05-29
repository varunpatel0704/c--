#include <stdio.h>
int main(){
    FILE * ptr;
    ptr=fopen("getcdemo.txt","r");
    char c;
    c=fgetc(ptr);//<--this will read the file char by char
    
    for (int i = 0; i < 10; i++)
    {
        printf("The character is: %c\n",c);
        c=fgetc(ptr);//<--this will read the file char by char
        
    }
    

    FILE *fp;
    fp=fopen("putcdemo.txt","w");
    fputc('c',fp);
    fputc('h',fp);
    fputc('a',fp);
    fputc('r',fp);
    char chr;
    
    
    
    chr=fgetc(ptr);
    while (chr!=EOF)
    {
        printf("%c",chr);//<-- this will print characters till file ends.
        chr=fgetc(ptr);
    }
    
    fclose(fp);
    fclose(ptr);
    
    return 0;
}