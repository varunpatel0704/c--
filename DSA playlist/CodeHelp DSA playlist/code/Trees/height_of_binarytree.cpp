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

int height(struct Node* node){
    // base case -> height of a leaf node is zero.
    if(node == NULL)
        return 0;
        
    // get the height of left subtree
    int hleft = height(node->left);
    
    // get the height of right subtree.
    int hright = height(node->right);
    
    // height of tree is maximum of left or right +1
    int htree = max(hleft, hright) + 1;
    return htree;
}

int main(){
    return 0;
}