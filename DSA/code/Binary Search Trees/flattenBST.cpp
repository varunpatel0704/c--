#include <iostream>
#include <vector>
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

void traversal(Node *root, vector<Node *> &inorder)
{
    if (root == NULL)
        return;

    inorder.push_back(root);
    traversal(root->left, inorder);

    traversal(root->right, inorder);
}

void flatten(Node *root)
{
    vector<Node *> inorder;
    if (root == NULL)
        return;
    traversal(root, inorder);
    int i = 0;
    for (i = 0; i < inorder.size() - 1; i++)
    {
        inorder[i]->right = inorder[i + 1];
        inorder[i]->left = NULL;
    }
    inorder[i]->right = NULL;
    inorder[i]->left = NULL;
}

int main(){
    
    return 0;
}