#include<iostream>
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

Node *findMiddle(Node *head) {
    
    if ( head == NULL || head->next == NULL)
        return head;
    
    Node* first = head;
    Node* second = head->next;
    
    while(second != NULL){
        
        second = second->next;
        if(second != NULL)
            second = second->next;
        
        first = first->next;        
    }
    return first;    
}

int main(){

    return 0;
}