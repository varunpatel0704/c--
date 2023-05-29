#include <iostream>
using namespace std;

class Node{

    public:

    int data;
    Node* next;
    Node* prev;
    Node(){}

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert(Node* &head, int data, int element){
    Node* newnode = new Node(data);

    // when list is empty.
    if(head == NULL){
        head = newnode;
        newnode->next = head;
        head->prev = newnode;
        return;
    }

    Node* temp = head;
    while(temp->data != element){
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next->prev = newnode;
}

void print(Node* head){
    if(head == NULL)
        return;
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!= head);
    cout<<endl;
}

void deletion(Node* head, int element){
    Node* curr = head->next;
    Node* previous = head;
    

    while(curr->data != element){
        previous = curr;
        curr = curr->next;
    }
    
    if(curr == previous){
        head = NULL;
        return;
    }

    if(curr == head)
        head = previous;

    previous->next = curr->next;
    curr->next = NULL;
    previous->next->prev = previous;
    curr->prev = NULL;
    delete curr;
   
}

int main(){
    Node* head = NULL;
    insert(head, 98, -1);
    insert(head, 61, 98);
    insert(head, 20, 98);
    insert(head, 39, 61);
    
    print(head);

    deletion(head, 98);

    print(head);
    return 0;
}