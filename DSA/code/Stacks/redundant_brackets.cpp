#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &str) {
    // Write your code here.
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        // incoming character is an open bracket or an operator.
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
          s.push(ch);
        }

        // incoming character is a closed bracket
        else{
            // there should be atleast one operator b/w
            // closed bracket and open bracket.
            if(ch == ')'){
                char top = s.top();
                
                bool redundant = true;
                // if the immediate pop is a closed bracket 
                // then the expression has redundant brackets
                while(top != '('){
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        redundant = false;
                    }
                    s.pop();
                    top = s.top();
                }

                // control is out of loop i.e. open bracket reached
                s.pop();
                if(redundant)
                    return true;
            }
        }
    }
    return false;
}


int main(){
    
    return 0;
}