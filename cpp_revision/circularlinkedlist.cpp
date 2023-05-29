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

void insert(Node* &head, int data, int element){
    Node* newnode = new Node(data);
    // when the list is empty.
    if(head == NULL){
        head = newnode;
        newnode->next = head;
        return;
    }

    // otherwise.
    Node* temp = head;
    while(temp->data != element){
        temp = temp->next;        
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void print(Node* head){
    if(head == NULL)
        return;
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
}

void deletion(Node* &head, int element){
    if(head == NULL)
        return;
    
    Node* curr = head->next;
    Node* prev = head;

    //cout<<curr->data<<" "<<prev->data<<endl;
    if(curr == prev){
        head = NULL;
        delete head;
        return;
    }

    while(curr->data != element){
        prev = curr;
        curr = curr->next;
    }

    if(curr == head){
        head = head->next;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        return;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;

}

int main(){
    Node* head = NULL;
    insert(head, 10, -1);
    insert(head, 18, 10);
    insert(head, 47, 10);
    insert(head, 31, 47);
    insert(head, 69, 18);
    
    print(head);

    deletion(head, 69);

    print(head);
    return 0;
}