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


Node* solve(Node* first, Node* second){
    
    Node* curr1 = first;
    Node* next1 = curr1->next;
    
    Node* curr2 = second;
    Node* next2 = curr2->next;
    
    if(next1 == NULL){
        curr1->next = curr2;
    }
   
    
    while(next1!=NULL && curr2!=NULL){
        if((curr2->data >= curr1->data) and (curr2->data <= next1->data)){
            
            next2 = curr2->next; 
           
            curr2->next = next1; // inserting second list's element into first list.
            curr1->next = curr2;
            
            
            curr2 = next2; // updating curr2.
            
            
            
            curr1 = curr1->next; // updating curr1, no need to update next1 as
                                 // next element from second list might fit in b/w new curr1 
                                 // and existing next . 
        }
        
        
        else{
            curr1 = next1;
            next1 = next1->next;
            
            if(next1 == NULL){ // first list exhausted.
                curr1->next = curr2;
                return first;
            }

        }
    }
    
    return first;
}


Node* sortedMerge(Node* first, Node* second)  
{  
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    
    if(first->data < second->data){
        solve(first, second);
    }
    
    else{
        solve(second, first);
    }
    
}

int main(){
    
    return 0;
}