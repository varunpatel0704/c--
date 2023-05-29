#include <iostream>
using namespace std;

class stack{
    // data members.
    private:
    int size;
    int top;
    int *arr;

    public:
    // constructor.
    stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size + 1];

        cout << "Stack of size " << size << " created"<<endl;
    }

    void push(int data){
        // check if the stack has space for more elements.
        if(top >= size-1)
            cout <<"Stack Overflow!" <<endl;
        else
            arr[++top] = data;
    }

    void pop(){
        // check whether the stack is already empty.
        if(top == -1)
            cout << "Stack Underflow" << endl;
        else    
            top--;
    }

    bool isEmpty(){
        return (top < 0);
    }

    void peek(){
        if(isEmpty())
            cout << "Stack is empty" << endl;
        else    
            cout <<"stack top ->"<< arr[top] << endl;
    }

    void print(){
        if(isEmpty())
            cout << "Stack is empty" << endl;
        else{
            int i = top;
            while(i >= 0){
                cout << arr[i--] <<" ";
            }cout<<endl;
        }

    }
};

int main(){

    stack stk(4);
    // stk.push(1);
    // stk.push(2);
    // stk.push(3);
    // stk.push(4);

    stk.print();

    stk.pop();

    //stk.push(74);

    stk.print();

    stk.peek();

    cout<<"stack empty? --> "<<stk.isEmpty()<<endl;
    return 0;
}