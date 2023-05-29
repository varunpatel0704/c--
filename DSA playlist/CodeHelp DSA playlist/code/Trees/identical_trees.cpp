#include <iostream>
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

bool isSameTree(Node* p, Node* q) {
    if(p == NULL && q == NULL)
        return true;
    if((p==NULL && q!=NULL) or(p!=NULL && q==NULL))
        return false;
    
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    
    if(p->data == q->data && left && right) // if p and q have same value and left and right subtrees are also equal, then it is identical.
        return true;
    else
        return false;
}

int main(){
    
    return 0;
}