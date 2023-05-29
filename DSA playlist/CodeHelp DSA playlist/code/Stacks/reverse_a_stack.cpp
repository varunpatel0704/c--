#include <iostream>
#include <stack>
using namespace std;

// recursive method to reverse a stack.

void insertatbottom(stack<int> &s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();
    
    insertatbottom(s, element);

    s.push(top);

}


void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty())
        return;
    
    // keep the top most element aside for 
    // the moment and reverse the remaining stack

    int element = stack.top();
    stack.pop();

    reverseStack(stack);
    
    // after the stack is reversed, insert the element at 
    // the bottom.
    insertatbottom(stack, element);


}

int main(){
    
    return 0;
}