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

int res = 0;
int solve( Node *root) {
    if(root==NULL)
        return 0;

    int hleft = solve(root->left);
    int hright = solve(root->right);

    res = max(res, hleft + hright + 1); // updating the diameter

    return max(hleft, hright)+1; // returning heights of the tree w.r.t current node or 
                                // simply the height of current subtree
}

int diameterOfBinaryTree(Node* root) {
    solve(root);
    return res - 1;
}


int main(){
    
    return 0;
}