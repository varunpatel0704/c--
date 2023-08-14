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

Node* findmid(Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

Node* merge(Node* head1, Node* head2){
    // if(head1 == NULL)
    //     return head2;
    // if(head2 == NULL)
    //     return head1;
    
    // Node* ans = new Node(-1);
    // Node* temp = ans;
    
    // while(head1 != NULL && head2 != NULL){
    //     if(head1->data < head2->data){
    //         temp->next = head1;
    //         temp = head1;
    //         head1 = head1->next;
    //     }
        
    //     else{
    //         temp->next = head2;
    //         temp = head2;
    //         head2 = head2->next;
    //     }
    // }
    
    // while(head1 != NULL){
    //     temp->next = head1;
    //     temp = head1;
    //     head1 = head1->next;
    // }
    
    // while(head2 != NULL){
    //     temp->next = head2;
    //     temp = head2;
    //     head2 = head2->next;
    // }
    
    // ans = ans->next;
    // return ans;
    
    
    
    Node* curr1 = head1, *next1 = head1->next;
    Node* curr2 = head2;
    
    if(next1 == NULL)
        curr1->next = curr2;
        
    while(next1 != NULL && curr2!=NULL){
        
        
        if(curr2->data >= curr1->data && curr2->data <= next1->data){
            Node* next2 = curr2->next;
            
            curr2->next = next1;
            curr1->next = curr2;
            
            curr1 = curr2;
            curr2 = next2;
        }
        
        else{
            curr1 = next1;
            next1 = next1->next;
        }
    }
    
    if(next1 == NULL)
        curr1->next = curr2;
    return head1;
}

Node* mergeSort(Node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }
    // step 1: find the mid of the LL
    Node* mid = findmid(head);
    
    // create two separate lists
    Node* right = head;
    Node* left = mid->next;
    mid->next = NULL;
    
    // repeat the process for left and right sub lists
    left = mergeSort(left); 
    right = mergeSort(right);
    
    
    // now merge both the sorted lists
    if(left->data < right->data){
        left = merge(left, right);
        return left;
    }
    
    else{
        right = merge(right, left);
        return right;
    }
    // Node* ans = merge(left ,right);
    // return ans;
}

int main(){
    
    return 0;
}