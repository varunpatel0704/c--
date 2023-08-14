#include <iostream>
#include <stack>
using namespace std;

bool isvalid(string s){
    stack <char> st;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        cout<<i<<endl;
        // bracket open.
        if(ch == '[' || ch == '{' || ch == '('){
            st.push(ch);
            cout<<"bracket open"<<endl;
        }

        // bracket close.
        else{
            // stack not empty.
            if(!st.empty()){
                cout<<"bracket close and stack not empty"<<endl;
                char top = st.top();
                //incoming parentheses and st.top parentheses matched.
                if((top == '(' && ch == ')') ||
                    (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']')){
                    cout<<"bracket matched"<<endl;
                    st.pop();
                }
                // dont match.
                else{
                    cout<<"bracket dont match"<<endl;
                    return false;
                }
            }

            // stack empty i.e. incoming parentheses has no matching counterpart in stack.
            else{
                cout<<"stack is empty"<<endl;
                return false;
            }

        }
    }
    // if stack is empty then, string is valid
    if(st.empty()){
        cout<<"valid string"<<endl;
        return true; 
    }
    cout<<"string invalid"<<endl;
    return false;
}

int main(){
    string s = "(){}[]";
    cout<<"string valid ? -->"<<isvalid(s)<<endl;
    // isvalid(s);
    return 0;
}