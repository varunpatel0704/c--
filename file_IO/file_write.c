#include <stdio.h>
int main(){
    FILE *fp;
    fp=fopen("generated.txt","w");
    int number=40;
    fprintf(fp,"The number is: %d",number);
    fprintf(fp,"\nThis file was created by Varun Patel.");
    fclose(fp);
    return 0;
}