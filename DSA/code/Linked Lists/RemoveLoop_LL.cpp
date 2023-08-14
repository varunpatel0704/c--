#include <iostream>
#include <map>
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

Node *removeLoop(Node *head)  // using maps.
{
    map<Node*, bool> visited;
    
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        if(visited[curr] == true)  // check if already visited before.
            break;
        else{
            visited[curr] = true;  // mark current node as visited and increment curr.
            prev = curr;
            curr = curr->next;
        }
    }
    
    prev->next = NULL; // remove loop by pointing  prev(last node) to NULL.
    
    return head;
}

Node* FloydCycleLoopDetection(Node* head){
    
    if(head == NULL)
        return NULL;

    Node* fast = head;
    Node* slow = head;

    while(slow!=NULL && fast != NULL){
        
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
        
        if(slow == fast)
            return slow;
    }
    return NULL;

}

Node* getStartingNode(Node* head){
    if(head == NULL)
        return NULL;

    Node* intersection = FloydCycleLoopDetection(head);
    if(intersection == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeloopfcd(Node* head){
    if(head == NULL)
        return;

    Node* stop = getStartingNode(head);
    if(stop == NULL)
        return;
    Node* temp = stop;
    while(temp->next != stop){
        temp = temp->next;
    }
    temp->next=NULL;
}

int main(){
    return 0;
}