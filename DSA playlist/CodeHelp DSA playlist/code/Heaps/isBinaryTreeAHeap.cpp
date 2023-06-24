#include <iostream>
#include <queue>
using namespace std;

class Node{

    public:

    int data;
    Node* left;
    Node* right;

    Node(){}

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isHeap(struct Node* tree) {

    if(tree == NULL)
        return true;
    
    bool isHeap=true;
    queue<Node*> q;
    q.push(tree);
    
    // traversing the heap in level order.
    while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp != NULL){
                q.push(temp->left);
                q.push(temp->right);
                
                /* if the right child exists and left child
                  does'nt, it is not a complete binary tree*/
                if(temp->left == NULL){
                    if(temp->right != NULL){
                        isHeap = false;
                        break;
                    }
                }
                
                /* control will be shifted to else if when atleast the 
                    left child exists. So we specifically need to check for right child's 
                    existence as well in the following condition */
                else if(temp->left->data > temp->data ||
                    (temp->right && temp->right->data > temp->data)){
                        isHeap = false;
                        break;
                    
                } 
                                                    
                
            }
            
            else{
                    if(!q.empty() and q.front()){
                        isHeap=false;
                        break;
                    }
                }
            
            
    }
    if(!isHeap)
        return false;
    else    
        return true;
}

int main(){
    
    return 0;
}