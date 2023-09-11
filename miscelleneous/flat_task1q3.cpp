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
    bool isValid = true;    // true if string is valid and false otherwise.

    cout<<"Enter the string (not more than 20 characters): ";
    cin>>str;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        char top = st.arr[st.top];

        if(st.isEmpty() || ch == top)
            st.push(ch);

        else if(ch != top)
            st.pop();

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