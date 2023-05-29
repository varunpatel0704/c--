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

// in this question we basically need to find the root of the subtree which contains both n1 and n2.
Node* lca(Node* root ,int n1 ,int n2 )
{
    //Your code here 
    if(root==NULL)
        return root;
    if( root->data == n1 || root->data == n2)
        return root;
    
    // check on the left hand side.
    Node* leftans = lca(root->left, n1, n2);
    Node* rightans = lca(root->right, n1, n2);
    
    // 4 possible combinations.
    // both n1 and n2 found.
    if(leftans!=NULL && rightans!=NULL)
        return root; // in that case root is our lca.
    // either one of them is found.
    if(leftans!=NULL and rightans==NULL)
        return leftans;
    if(leftans==NULL && rightans!=NULL)
        return rightans;
    // none of them is found.
    else
        return NULL;

}

int main(){
    return 0;
}