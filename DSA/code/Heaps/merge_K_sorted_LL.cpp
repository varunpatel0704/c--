#include <iostream>
#include <queue>
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

class compare{
    public:
        bool operator() (Node* a, Node* b){
            return (a->data > b->data);
        }
};

void insertAtTail(Node* &head, Node* &tail, Node* &node){
    if(head == NULL){
        head = node;
        tail = node;
        tail->next = NULL;
    }

    else{
        tail->next = node;
        tail = node;
        tail->next = NULL;
    }
}

Node* mergeKLists(vector<Node*>& lists) {
    if(lists.size()==0) 
        return NULL;
    // step 1: create a min heap.
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // step 2: enter the first node of all K lists in the minHeap
    for(int i=0; i<lists.size(); i++){
        if(lists[i] != NULL)
            minHeap.push(lists[i]);
    }

    Node* head=NULL, *tail=NULL;

    while(!minHeap.empty()){
        // step 3: now pop the top element and insert into output LL
        Node* temp = minHeap.top();
        minHeap.pop();

        // step 4: if a nodes exists next to the popped node, 
        // push it into heap
        if(temp->next){
            Node* next = temp->next;
            minHeap.push(next);
        }

        insertAtTail(head, tail, temp);
    }
    return head;
}


int main(){
    
    return 0;
}