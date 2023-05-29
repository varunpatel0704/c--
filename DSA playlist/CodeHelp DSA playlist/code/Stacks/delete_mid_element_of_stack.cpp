#include <iostream>
#include <stack>
using namespace std;

void deleteMid(stack<int>&s, int sizeOfStack)
{
    // recursive solution 
    // base case
    if(s.size() == ((sizeOfStack+1)/2)){
        s.pop();
        return;
    }
    
    int element = s.top();
    s.pop();
    
    deleteMid(s, sizeOfStack);
    
    //backtrack
    s.push(element);
}

int main(){
    
    return 0;
}