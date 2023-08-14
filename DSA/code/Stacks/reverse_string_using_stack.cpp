#include <iostream>
#include <stack>
using namespace std;

char* reverse(char *S, int len)
{
    //code here
    stack <char> stk;
    
    // inserting characters in stack.
    for(int i = 0; i < len; i++){
        stk.push(S[i]);
    }
    
    // creating dynamic char array
    char* arr = new char[len];
    
    for(int i = 0; i < len; i++){
        char ch = stk.top();
        arr[i] = ch;
        stk.pop();
    }
    
    return arr;
}

int main(){
    
    return 0;
}