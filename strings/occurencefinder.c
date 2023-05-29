#include <stdio.h>

int occurence(char str[], char c)
{

    int i = 0, count = 0;
    while (str[i] != '\0')
    {
        if (*(str+i) == c)
        {
            count++;
        }
        i++;
    }
    return count;
}
char * slice(char * str, int a, int b){
    int i=0;
    while(a<b){
        str[i]=str[a];
        i++;
        a++;
    }
    str[i]='\0';
    return str;
}

int main()
{
    char c, str[50];
    printf("Enter the string to find occurence: ");
    gets(str);

    printf("Which char's occurence do you want to find? ");
    scanf("%c", &c);

    printf("%c has %d occurence(s) in the given string: ", c, occurence(str, c));
   
    printf("\nsliced string is %s",slice(str, 1, 3)) ;
    
    return 0;

}