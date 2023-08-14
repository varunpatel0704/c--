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

Node* kReverse(Node* head, int k) {
    
    // base case. Stop since we have reached the end of LL.
    if(head == NULL)
        return head;
    
    Node* prev = NULL;
    Node* curr = head;
    Node* temp = NULL;
    int cnt = 0;
    
    while(curr != NULL && cnt<k){  // reversing first k nodes
        temp = curr->next;
        
        curr->next = prev;
        prev = curr;
        curr = temp;
        cnt++;
    }
        
    head->next = kReverse(curr, k); // curr is the new head for next part of LL;
    
    return prev;

}

int main(){
    
    return 0;
}