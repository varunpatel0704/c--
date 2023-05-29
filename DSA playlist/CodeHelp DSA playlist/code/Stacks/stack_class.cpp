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

    void pop(){
        // check if array is empty or not before poppig.
        if(isEmpty()){
            cout << "Stack underflow" << endl;
        }

        else{
            top--;
        }
    }

    void peek(){
        if(isEmpty())
            cout << "Stack empty" << endl;
        
        else{
            cout << arr[top] << endl;
        }
            
    }

    bool isEmpty(){
        return (top < 0);
    }


};


int main(){
    
    stack stk1(5);

    stk1.push(3);
    stk1.push(5);
    stk1.push(7);

    stk1.peek();

    stk1.pop();
    stk1.pop();
    stk1.pop();
    stk1.pop();

    stk1.peek();
    
    cout << "Stack empty? -->" << stk1.isEmpty() << endl;

    return 0;
}