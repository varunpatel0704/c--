#include <stdio.h>
int main(){
    FILE *ptr, *fp;
    ptr=fopen("a.txt","r");
    fp=fopen("b.txt","w");
    char c;
    c=fgetc(ptr);
    for(int i=0; i<2; i++){
        while(c!=EOF){
            //fprintf(fp,"%c",c);
            putc(c,fp);
            c=fgetc(ptr);
        }
    }
    return 0;
}