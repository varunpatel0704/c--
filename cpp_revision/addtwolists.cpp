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

void reverse(   Node* &head){
       Node* curr = head;
       Node* prev = NULL;
    
    while(curr != NULL){
           Node* next = curr->next;
        
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    head = prev;
}

void insertAtTail(   Node* &head,    Node* &tail, int data){
       Node* newnode = new Node(data);
    
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

//Function to add two numbers represented by linked list.
   Node* addTwoLists(   Node* first,    Node* second)
{
    // code here
    reverse(first);
    reverse(second);
    
       Node* anshead = NULL;
       Node* anstail = NULL;
    int sum = 0, carry = 0;
    while(first != NULL || second != NULL || carry){
        if(first != NULL && second != NULL ){
            cout<<first->data<<" "<<second->data<<endl;
            sum = first->data + second->data + carry;
            int digit = sum%10;
            insertAtTail(anshead, anstail, digit);
            carry = sum/10;
            first = first->next;
            second = second->next;
        }
        
        else if(first != NULL){
            cout<<first->data<<endl;
            sum = first->data  + carry;
            int digit = sum%10;
            insertAtTail(anshead, anstail, digit);
            carry = sum/10;
            first = first->next;
        }
        
        else if(second != NULL){
            cout<<second->data<<endl;
            sum = second->data  + carry;
            int digit = sum%10;
            insertAtTail(anshead, anstail, digit);
            carry = sum/10;
            second = second->next;
        }
        
        else{
            insertAtTail(anshead, anstail, carry);
            carry = 0;
        }
    }
    reverse(anshead);
    return anshead;
}

void print(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }cout<<endl;
}

int main(){
    Node* head = NULL;
    insert(head, 2, 1);
    insert(head, 3, 1);
    insert(head, 0, 1);
    insert(head, 7, 1);
    insert(head, 7, 1);    

    print(head);
    cout<<endl;

    Node* head2 = NULL;
    insert(head2, 0, 1);
    insert(head2, 6, 1);
    insert(head2, 6, 1);
    insert(head2, 9, 1);
    insert(head2, 2, 1);
    print(head2);

    Node* ans = addTwoLists(head, head2);
    print(ans);
    return 0;
}