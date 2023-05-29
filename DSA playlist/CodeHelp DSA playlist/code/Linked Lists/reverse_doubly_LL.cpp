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

int main(){
    
    return 0;
}