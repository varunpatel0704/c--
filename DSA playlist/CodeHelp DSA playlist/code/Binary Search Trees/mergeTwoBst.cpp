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

void inorder(Node *root, vector<int> &tree)
{
    if (root == NULL)
        return;

    inorder(root->left, tree);

    tree.push_back(root->data);

    inorder(root->right, tree);
}

Node *merge(vector<int> &tree, int i, int j)
{
    if (i > j)
        return NULL;

    int mid = (i + j) / 2;
    Node *newnode = new Node(tree[mid]);

    newnode->left = merge(tree, i, mid - 1);
    newnode->right = merge(tree, mid + 1, j);

    return newnode;
}

Node *mergeBST(Node *root1, Node *root2)
{
    vector<int> tree1, tree2;
    inorder(root1, tree1);
    inorder(root2, tree2);

    vector<int> tree;

    int i = 0, j = 0;
    while (i < tree1.size() && j < tree2.size())
    {
        if (tree1[i] < tree2[j])
            tree.push_back(tree1[i++]);
        else
            tree.push_back(tree2[j++]);
    }
    while (i < tree1.size())
    {
        tree.push_back(tree1[i++]);
    }
    while (j < tree2.size())
    {
        tree.push_back(tree2[j++]);
    }

    Node *root = merge(tree, 0, tree.size() - 1);
    return root;
}

int main(){
    
    return 0;
}