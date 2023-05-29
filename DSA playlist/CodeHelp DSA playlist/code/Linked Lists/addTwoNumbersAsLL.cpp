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

void insertAtTail(Node* &tail, int data){
        
    Node* newnode = new Node(data);
    
    tail->next = newnode;
    tail = newnode;
    
}

Node* add(Node* first, Node* second){
    
    Node* ans = new Node(-1);
    Node* tail = ans;
    
    int sum = 0, carry = 0;
    
    while(first != NULL or second != NULL or carry!=0){
        int digit1 = 0;
        
        if(first!=NULL)   // only find value of first list's element if it is not empty.
            digit1 = first->data;

        int digit2 = 0;
        if(second != NULL)
            digit2= second->data;
         
        
        sum = digit1 + digit2 + carry;
        
        carry = sum/10;
        sum = sum%10;
        
        insertAtTail(tail, sum);

        if(first != NULL) // increment only if not empty already.
            first = first->next;
        if(second != NULL)
            second = second->next;        
    }    
    return ans->next;
}

void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;
    while(curr != NULL){
        next = curr->next;
        
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    
}

//Function to add two numbers represented by linked list.
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // step-1: reverse input LL.
    reverse(first);
    reverse(second);
    
    // step-2: add both lists.
    Node* ans = add(first, second);
    
    // step-3: reverse ans.
    reverse(ans);
    
    return ans;
}

int main(){
    
    return 0;
}