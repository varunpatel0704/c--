#include <iostream>
using namespace std;

//Given a circular linked list. Split it into two halves where each half is a CLL.

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


void splitList(Node *head, Node *head1, Node *head2)
{
    // your code goes here
    if(head == NULL or head->next == NULL)
        return;
        
    Node* slow = head;
    Node* fast = head->next;
    while(fast->next != head){
        fast = fast->next;
        if(fast->next!=head)
            fast = fast->next;
            
        slow = slow->next;
    }
    
    fast->next = slow->next;
    slow->next = head;
    
    head1 = head;
    head2 = fast->next;
}

int main(){
    
    return 0;
}