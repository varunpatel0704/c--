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

bool isCircular(Node* head){
  
    if(head == NULL)
        return true;
    if(head->next == NULL)
        return false;
   
    Node* temp = head->next;
    while(temp != NULL){
        
        if(temp->data == head->data)
            return true;
        temp = temp->next;
    
    }
    
    return false;
}

int main(){
    
    return 0;
}