#include <iostream>
#include <math.h>
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

int height(Node* node){
        
    // base case.
    if(node==NULL)
        return 0;
    
    // first of all find the heights of left and right 
    // sub trees 
    int left=height(node->left);
    int right=height(node->right);
    
    // the height of current sub tree will be the 
    // maximum of left and right heigths.
    int hmax=max(right, left)+1;
    return hmax;
    
}

bool isBalanced(Node *root)
{
    if(root==NULL){
        return true;
    }
    
    // check if left and right subtrees are balanced or not
    bool leftbal=isBalanced(root->left);
    bool rightbal=isBalanced(root->right);
    
    // now check if current node is balanced or not.
    int lefth=height(root->left);
    int righth=height(root->right);
    
    bool hbal= abs(lefth-righth)<=1;
    if(hbal && leftbal && rightbal)
        return true;
    else
        return false;
}

int main(){
    
    return 0;
}