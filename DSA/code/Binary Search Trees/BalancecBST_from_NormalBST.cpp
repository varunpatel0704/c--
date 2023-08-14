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

void traversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    traversal(root->left, inorder);

    inorder.push_back(root->data);

    traversal(root->right, inorder);
}

Node *build(vector<int> &inorder, int i, int j)
{
    if (i > j)
        return NULL;

    int mid = i + (j - i) / 2;
    Node *root = new Node(inorder[mid]);
    root->left = build(inorder, i, mid - 1);
    root->right = build(inorder, mid + 1, j);

    return root;
}

Node *buildBalancedTree(Node *root)
{
    // Code here
    vector<int> inorder;
    traversal(root, inorder);

    int i = 0, j = inorder.size() - 1;

    root = build(inorder, i, j);
    return root;
}

int main(){
    return 0;
}