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

void insert(Node* &head, int data, int pos){
    Node* newnode = new Node(data);

    // position is 1, insert the element at head.
    if(pos == 1){
        newnode->next = head;
        head = newnode;
        return;
    }

    // insertion at positions except head.
    Node* temp = head;
    int i = 1;
    while(i < pos-1){
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;

}

void deletion(Node* &head, int pos){
    Node* curr = head;
    // delete head.
    if(pos == 1){
        head = head->next;
        curr->next = NULL;
        delete curr;
        return;
    }
    int i = 1;
    Node* previous = NULL;
    while(i < pos){
        previous = curr;
        curr = curr->next;
        i++;
    }

    previous->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }cout<<endl;
}

int main(){
    Node* head = NULL;
    insert(head, 10, 1);
    insert(head, 9, 1);
    insert(head, 8, 1);
    insert(head, 69, 2);
    
    print(head);

    deletion(head, 2);

    print(head);

    return 0;
}