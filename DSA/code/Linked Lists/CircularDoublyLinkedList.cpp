#include <iostream>
using namespace std;

class Node{
    public:
    int data;

    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertNode(Node * &head, int element, int data){

    if(head == NULL){
        Node* newnode = new Node(data);
        head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;

        return;
    }

    else{

        Node* temp = head;
        while(temp->data != element){
            temp = temp->next;
        }

        // reached the node with value equal to element, now insert new node after this.
        Node* newnode = new Node(data);
        
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
        newnode->prev = temp;
        return;
    }

}

void deleteNode(Node* &head, int element){

    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* previous = head;
    Node* curr = previous->next;
    while (curr->data != element)
    {
        previous = curr;
        curr = curr->next;
    }
    
    previous->next = curr->next;
    curr->next = NULL;
    previous->next->prev = previous;
    curr->next = NULL;

    // befor deleting curr, some conditions need to be checked.
    if(curr == head)
        head = previous;


    if(curr == previous)
        head = NULL;

    delete curr;


}

void print(Node* head){
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;

    do{
        
        cout<<temp->data<<" ";
        temp = temp->next;
    
    }while(temp != head);
    
    cout<<endl;
    
}

int main(){

    Node* n1 = new Node(9);
    Node* head = n1;

    n1->next = n1;
    n1->prev = n1;

    insertNode(head, 9, 101);
    print(head);

    insertNode(head, 101, 67);
    print(head);
    
    insertNode(head, 101, 55);
    print(head);
    
    insertNode(head, 67, -49);
    print(head);

    deleteNode(head, 101);
    print(head);

    return 0;
}