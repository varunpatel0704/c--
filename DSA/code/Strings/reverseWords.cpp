#include <iostream>
using namespace std;

void reverse(char st[], int start, int end){
    while (start<=end)
    {
        swap(st[start], st[end]);
        start++, end--;
    }
    
}

void revWords(char st[]){

    int i=0, j=0;
    while (st[i]!='\0')
    {
        if(st[i]==' '){
            reverse(st, j, i-1); // <-- reversing individual words.
            j=i+1;
        }
        i++;
    }
    reverse(st, j, i-1);// <-- reversing the last word.
   
    reverse(st, 0, i-1); // <-- Reversing the entire string.

}

int main(){
    char str[100];
    
    cout<<"Enter a sentence ";
    gets(str);
    
    revWords(str);
    
    cout<<str;
   
    return 0;
}