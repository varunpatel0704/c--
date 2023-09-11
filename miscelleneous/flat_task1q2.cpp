#include <iostream>
using namespace std;

class stack{
    public:

    int* arr;
    int top;
    int size;

    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        // check if array is full before push operation.
        if(top < size - 1){
            top++;
            arr[top] = element;
        }   

        else{
            cout <<"Stack overflow" << endl ;
        }
    }

    int pop(){
        // check if array is empty or not before poppig.
        if(isEmpty())
            return -1;

        else
            return arr[top--];
        
    }

    bool isEmpty(){
        return (top < 0);
    }
};

int main(){
    stack st(20);
    string str;
    bool flag = false;      // flag tells us if 'c' has appeared in the string.
    bool isValid = true;    // true if string is valid and false otherwise.

    cout<<"Enter the string (not more than 20 characters): ";
    cin>>str;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if((ch == 'a' || ch == 'b') && (!flag)){
            st.push(ch);
        }

        else if(ch == 'c')
            flag = true;

        else if(ch == 'a' || ch == 'b' && flag){
            char top = st.arr[st.top];  
            
            // character at stack top should match the incoming character
            if(top == ch)
                st.pop();

            else{             
                isValid = false;
                break;
            }
        }    

        else{
            isValid = false;
            break;
        }
    }

    if(!isValid)
        cout<<"String is invalid"<<endl;

    else if(!st.isEmpty())
        cout<<"String is invalid"<<endl;

    else    
        cout<<"String is valid"<<endl;
        
    return 0;
}