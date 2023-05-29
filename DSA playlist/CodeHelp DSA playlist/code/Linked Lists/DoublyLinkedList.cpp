#include <iostream>
using namespace std;

class Node{
    public:
    
    int data;
    Node* prev;
    Node* next;

    Node(){}
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head->prev=temp;
    head = temp;
}

void insertAtPos(Node* &head, int data, int pos){
    Node* newnode = new Node(data);
    Node* temp = head;
    
    if(pos == 1){
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }

    int i = 1;
    while(i < pos-1){
        temp = temp->next;
        i++;
    }
    
    if(temp->next == NULL){
        temp->next=newnode;
        newnode->prev=temp;
        return;
    }
   
    newnode->next = temp->next;
    (newnode->next)->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;

}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void deletePos(Node* &head, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;
    }

    else{
        Node* curr;
        Node* previous; 
        curr = head->next;
        previous = head;
        
        int i = 1;
        while(i < pos-1 ){
            curr = curr->next;
            previous = previous->next;
            i++;
        }
        if(curr->next == NULL){
            curr->prev=NULL;
            previous->next=NULL;
            delete curr;
            return;
        }
        
        
        previous->next = curr->next;
        curr->next = NULL;
        (previous->next)->prev = previous;
        curr->prev = NULL;
        
        delete curr;
        

        // curr->prev=NULL;
        // previous->next=curr->next;
        // curr->next=NULL;
        // previous->next->prev=previous;
    }

}

void print(Node* &head){
    Node * temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp -> next;
    }cout<<endl;
    
}

void reverse(Node* &head){
    if(head == NULL)
        return;
    
    Node* end = head;
    while(end->next !=NULL ){
        end = end->next;
    }

    Node* start = head;

    while(start != end){
        int temp = start->data;
        
        start->data = end->data;
        end->data = temp;

        start=start->next;
        if(start!=end)
            end = end->prev;
    }
}

int getLength(Node* &head){
    Node* temp = head;
    int len=0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    
    return len;
}

int main(){
    
    Node* n1 = new Node(45);
    Node* head = n1;
    Node* tail = n1;
    print(head);

    insertAtHead(head, 23);
    insertAtHead(head, 58);
    insertAtHead(head, 10);
    
    insertAtTail(tail, 67);
    
    print(head);
  
    insertAtPos(head, 91, 4);
    insertAtPos(head, -101, 1);
    insertAtPos(head, 26, 8);
    print(head);

    cout<<tail->data<<endl;
    cout<<tail->prev->data<<endl;
    cout<<tail->prev->prev->data<<endl;

    reverse(head);
    // deletePos(head, 8);
    print(head);
    //cout<< "Length of DLL is " << getLength(head) <<endl;
    return 0;
}