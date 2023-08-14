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

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    // 3 possible cases.
    // p belongs to left subtree and q belongs to right subtree
    // or vice-versa.
    
    if (p->data > root->data && q->data < root->data ||
        p->data < root->data && q->data > root->data)
    {
        return root;
    }
    // p and q belong to same left or right subtree.

    else if (p->data < root->data && q->data < root->data)
    {   
        Node* ans = lowestCommonAncestor(root->left, p, q);
        return ans;
    }

    else if (p->data > root->data && q->data > root->data)
    {   
        Node* ans = lowestCommonAncestor(root->right, p, q);
        return ans;
    }
}

Node* LCA(Node *root, Node* p, Node* q)  // iterative solution.
{
    while (root != NULL)
    {

        if (p->data < root->data && q->data < root->data)
        {
            root = root->left;
        }

        else if (p->data > root->data && q->data > root->data)
        {
            root = root->right;
        }

        else
            return root;
    }
}

int main(){
    
    return 0;
}