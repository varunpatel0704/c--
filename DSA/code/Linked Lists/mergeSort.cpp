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

Node* merge(Node* left, Node* right){

    Node* curr1 = left;
    Node* next1 = curr1->next;
    Node* curr2 = right;
    Node* next2 = curr2->next;

    while(next2 != NULL and curr2!= NULL){
        next2 = curr2;
        curr2->next = next1;
        curr1->next = curr2;

        curr1 = curr1->next;
        curr2 = next2;
    }

    return left;

}

Node* mergeSort(Node* head){
    if (head == NULL || head->next == NULL)
        return head;
    
    Node* left = head;

    Node* fast = head->next;
    Node* slow = head;
    
    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    Node* right = slow->next;
    slow->next = NULL;

    // sort left part
    mergeSort(left);
    
    // sort right part
    mergeSort(right);

    // merge left and right parts
    if(left->data < right->data){
        head = merge(left, right);

    }

    else{
       head = merge(right, left);
    }

    return head;
}

int main(){
    
    return 0;
}