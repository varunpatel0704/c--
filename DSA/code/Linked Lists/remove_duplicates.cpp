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

void insertAtHead(Node* &head, int data){

    // creating a new node to insert data.
    Node *temp = new Node(data);
    
    temp->next = head; // linking temp to node next to it.
    
    head = temp; // updating head pointer to make it point towards new node. 
}

void print(Node* &head){
    Node *temp = head; // here temp is the control variable used to traverse the LL.
    
    while(temp != NULL){
        cout << (*temp).data << " ";
        temp = (*temp).next; // temp = temp -> next; or simply tail = temp;
    }
    cout<<endl;
}


// for sorted linked list.
Node* deleteDuplicates(Node* head) {  
    if(head == NULL)
        return NULL;

    Node* curr = head;
    while(curr!=NULL){
        if( (curr->next != NULL)  &&  (curr->data == curr->next->data)){

            Node* next_next = curr->next->next;
            Node* nodetodelete = curr->next;
            delete nodetodelete;
            curr->next = next_next;

        }

        else{
            curr = curr->next;
        }

    }

    return head;

}


// for unsorted linked list.
Node *removeDuplicates(Node *head)    // using map.
{
    // Write your code here
    if(head == NULL)
        return head;
    
    
    Node* curr = head;
    Node* prev = NULL;
    map<int, bool> visited;
    while(curr!= NULL){
    
        int data = curr->data;
        if(visited[data] == true){  // if already visited then, delete current node.

            Node* del = curr;
            curr = curr->next;    // not incrementing prev as the next element(now curr) may
            prev->next = curr;    // also be one which is already visited, hence we may need to  
            del->next = NULL;     // delete that as well.
            
            delete del;

        }
        
        else{
            visited[data] = true; // visiting first time.
            prev = curr;          // so incrementing prev and curr both.
            curr = curr->next;
        }
    }
    return head;
}


// for unsorted linked list.
void removeduplicates(Node* head){   // using nested loop.
    Node* curr = head;
    
    while(curr!=NULL){
        
        Node* temp = curr->next;
        
        while(temp!=NULL){
           
            if(curr->data == temp->data){
                Node* del = temp;
                temp = temp->next;
                del->next = NULL;
                delete del;
            }
            else
                temp = temp->next;
        }
        curr = curr->next;
    }

}

int main(){
    // 5 0 4 3 4 2 0 1 2
    Node* head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    insertAtHead(head, 2);
    insertAtHead(head, 4);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 0);
    insertAtHead(head, 5);
    print(head);

    removeduplicates(head);
    print(head);
    return 0;
}