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

bool isPalindrome(Node *head){

    Node* curr = head;
    Node* prev = NULL;
    
    int num = 0;
    
    while(curr!=NULL){
        int digit = curr->data;
        num = num*10 + digit; // forming the original number and storing in num.
        
        Node* next = curr->next;
        
        curr->next = prev; // reversing the LL.
        
        prev = curr;
        curr = next;
    }
    
    head = prev;
    int revnum = 0;
    
    while(prev!=NULL){
        int digit = prev->data; // forming the reverse number.
        revnum = revnum*10 + digit;
        
        prev = prev->next;
    }
    
    if(revnum == num)
        return true;
        
    else
        return 0;
}


int main(){
    
    return 0;
}