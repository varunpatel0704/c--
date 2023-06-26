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

// recursive solution.
int nodeCount(Node* root){
    if(root == NULL)
        return 0;
    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

bool isCBT(Node* root, int index, int cnt){
    if(root == NULL)
        return true;
    
    if(index > cnt) // right node exists while left sibling is NULL, which violate CBT property
        return false;
    
    bool left = isCBT(root->left, index*2, cnt);
    bool right = isCBT(root->right, index*2 + 1, cnt);
    
    return left&&right;
}

bool isMaxHeap(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return true;
    
    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);
    
  /* since isMaxHeap function will be called only if tree is CBT,
     the left child is guaranteed to exist.
     hence there are 3 cases, node is a leaf node(already handled in base case)
     or only left child exists, or both children exist */
    
    // case 2:
    if(root->right == NULL){
        // then just check whether left child is greater than current node.
        if(root->left->data > root->data)
            return false;
    }
    
    // case 3:
    else{
        bool condition = (root->left->data < root->data && 
                            root->right->data < root->data);
        return (left && right && condition);
    }
}

bool isHeap(struct Node* tree) {
    // step 1: find total no of nodes
    int cnt = nodeCount(tree);
    
    int index = 1;
    // step 2: check if tree is CBT and follows Max heap property
    if(isCBT(tree, index, cnt) && isMaxHeap(tree))
        return true;
    else
        return false;
}



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
            // if there is any non NULL element left after poping the q 
            // it means that there is a NULL element b/w two nodes in level order.
            // since the deleted element(temp) was null but the new element at q
            // front is not null.
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