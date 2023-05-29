#include <iostream>
#include <stack>
using namespace std;

void insertatbottom(stack<int>& s, int x){
    if(s.empty()){   
        s.push(x);
        return;
    }
    
    int element = s.top();
    s.pop();

    insertatbottom(s, x);

    s.push(element);
}

int main(){
    
    return 0;
}