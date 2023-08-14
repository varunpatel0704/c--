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


Node* segregate(Node *head) {   // overwriting data values.
    if(head == NULL)
        return head;
    // Add code here
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node* temp = head;
    
    while(temp != NULL){
        int data = temp->data;
        if(data == 0)
            count0++;
            
        else if(data ==1)
            count1++;
        
        else if(data == 2)
            count2++;
        temp = temp->next;
    }
    
    temp = head;
    
    while(temp!=NULL){
        if(count0){
            temp->data = 0;
            count0--;
        }
        
        else if(count1){
            temp->data = 1;
            count1--;
        }
        
        else if(count2){
            temp->data = 2;
            count2--;
        }
        temp=temp->next;
        
    }
    return head;
}


void insertAtTail(Node* &tail, Node* temp){
        tail->next = temp;
        tail = temp;
    }

Node* sort(Node *head) { 
    if(head == NULL)
        return head;

    Node* zerohead = new Node(-1);  // dummy pointers to initialize 3 LL for 0s, 1s, 2s
    Node* zerotail = zerohead;
    
    Node* onehead = new Node(-1);
    Node* onetail = onehead;

    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* temp = head;
    
    while(temp != NULL){

        if(temp->data == 0)
            insertAtTail(zerotail, temp);  // insert 0 to 0's LL if curr data is 0.
        
        else if(temp->data == 1)           // insert 1 to 1's LL if curr data is 1.
            insertAtTail(onetail, temp);
        
        else if(temp->data == 2)           // insert 2 to 2's LL if curr data is 2.
            insertAtTail(twotail, temp);
        
        temp = temp->next;
    }
    
    if(onehead->next != NULL)            // check if 1's LL is empty or not.
        zerotail->next = onehead->next;  
    
    else
        zerotail->next = twohead->next;  // if empty then attach 0's LL directly to 2's LL.

    onetail->next = twohead->next;
    twotail->next = NULL;
    
    head = zerohead->next;
    delete zerohead, onehead, twohead;

    return head;
}

int main(){
    
    return 0;
}