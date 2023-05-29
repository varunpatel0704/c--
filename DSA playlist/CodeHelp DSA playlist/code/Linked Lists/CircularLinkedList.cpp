#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){}

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertNode(Node* &head, int element, int data){
    // if LL is empty.
    if(head == NULL){
        Node* newnode = new Node(data);
        head = newnode;
        newnode->next = head;
        return;
    }

    else{

        Node* temp = head;
        while(temp->data != element){
            temp = temp->next;
        }
        // reached the node having value equal to element. Hence need to insert new node after current node.
        Node* newnode = new Node(data);
        newnode->next = temp->next;
        temp->next = newnode;

    }
}

void deleteNode(Node* &head, int value){

    if(head == NULL){
        cout<<"List empty"<<endl;
        return;
    }

    Node* prev = head;
    Node* curr = prev->next;

    while (curr->data != value)
    {   
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = curr->next;

    // if node count = 1.
    if(curr == prev){
        head = NULL;
    }

    // if node count >= 2 but node to delete is head.
    if(head == curr) // if we delete curr without doing below step then we lose access to list.
        head = prev; // point head to any node within the list so that we don't lose access to list.
    
    curr->next = NULL;
    delete curr;
    

}

void print(Node* head){
    if(head == NULL){
        cout<<"List empty"<<endl;
        return;
    }

    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp !=head);
    cout<<endl;

}



int main(){
    
    //Node* n1 = new Node(10);
    //n1->next = n1;  <-- it is imporatant to make sure to point the first node to itself.
    //Node* head = n1;
    
    Node* head = NULL;
    insertNode(head, 10, 5);
    print(head);

    insertNode(head, 5, 6);
    print(head);

    insertNode(head, 6, 7);
    print(head);

    insertNode(head, 7, 8);
    print(head);
    
    insertNode(head, 5, 101);
    print(head);

    // deleteNode(head, 5);
    // print(head);
    return 0;
}