#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){}
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){

    // creating a new node to insert data.
    Node *temp = new Node(data);
    
    temp->next = head; // linking temp to node next to it.
    
    head = temp; // updating head pointer to make it point towards new node. 
}

void insertAtTail(Node* &tail, int data){
    // creating new node for insertion at tail.
    Node *temp = new Node(data);
    
    tail->next = temp; 
    
    tail = temp; // or tail = tail -> next; 
}

void insertAtPos(Node* &head, Node* &tail, int data, int position){

    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node *temp = head; // creating iterator for traversal.    
    
    int i = 1;
    while(i < position-1){
        temp = temp -> next;
        i++;
    }
    
    if(temp -> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node * newnode = new Node(data);
    
    newnode->next = temp->next; // first joining tail of new node to head of existing node next to temp.
    temp->next = newnode; // then joining head of new node to tail of temp.
}

void deleteNode(Node* &head, int pos){

    if(pos == 1){               // since there is no previous node for head node, 
        Node *temp = head;      // we need to handle it in a different way.
        head = head -> next;    // pointing head to next node.
        temp->next = NULL;      // breaking link of previous block to current head block.
        delete temp;            // deleting previous head block.
        return;
    }

    else{
        
        Node* curr;                 
        Node* prev;                 
       
        curr = head->next;          // previous node and current node will stay adjacent to each other.
        prev = head;
        
        int i = 1;        
        while(i<pos-1){            
            curr = curr->next;
            prev = prev->next;   // traversing to position to be deleted.
            i++;
        }

        prev->next = curr->next; // breaking link b/w prev node and curr node and joining prev node to next node
        curr->next = NULL;       // breaking link of current node to new node.
        delete curr;             // deleting current node now that prev node and new node are joined 
        return;                  // and curr node is free from linked list.
    }

}

void print(Node* &head){
    Node *temp = head; // here temp is the control variable used to traverse the LL.
    
    while(temp != NULL){
        cout << (*temp).data << " ";
        temp = (*temp).next; // temp = temp -> next; or simply tail = temp;
    }
    cout<<endl;
}

void reverseList(Node* &head){
    if(head == NULL || head->next == NULL){
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* temp = NULL;
    while(curr != NULL){
        
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }cout<<endl;
    head = prev;
}

void recursivereverse(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    recursivereverse(head, curr->next, curr); // first reach the end of the list the start reversing
    curr->next = prev;                        // the link of each node.

}

int main(){
    
    Node *n1 = new Node(10);
    
    Node *head = n1;
    Node *tail = n1;
    print(head);
    
    insertAtHead(head, 29);
    print(head);

    insertAtTail(tail, 78);
    print(head);
    
    insertAtPos(head, tail, 101, 2);
    print(head);
    
    insertAtPos(head, tail, 98, 1); 
    insertAtPos(head, tail , 69, 6); 
    print(head);

    Node* curr = head;
    Node* prev = NULL;
    recursivereverse(head, head, NULL);
    cout<<"reversed list is ---> ";
    print(head);
    return 0;
}