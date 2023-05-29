#include <iostream>
using namespace std;

class Node{

    public:

    int data;
    Node* next;

    Node(){}

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class stack: public Node{ // implementing stack using linked list.
    public: 
    int count;
    int size;
    Node * head;

    stack(int size){
        this->size = size;
        this->count = 0;
        head = NULL;
    }

    void push(int element){
        if(count < size){
            Node * newnode = new Node(element);
            // if(head == NULL){
            //     head = newnode;
            // }

            // else{
                newnode->next = head;
                head = newnode;
                count++;
            //}
        }
        else
            cout<<"stack overflow"<<endl;
    }

    void pop(){
        if(count > 0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else
            cout<<"stact underflow"<<endl;
    }
    
    void peek(){
        if(head != NULL)
            cout<< head->data <<endl;
        else
            cout<<"stack empty"<<endl;
    }

    bool isEmpty(){
        return (head == NULL);
    }

};

int main(){
    
    stack s1(4);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    
    s1.push(5);

    s1.peek();

    s1.pop();

    s1.peek();

    cout<<"stack empty? -->"<<s1.isEmpty()<<endl;


    return 0;
}