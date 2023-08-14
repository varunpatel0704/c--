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

Node *ancestor(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;
    if (root->data == node)
    {
        // k--;
        return root;
    }

    Node *left = ancestor(root->left, k, node);
    Node *right = ancestor(root->right, k, node);

    if (left != NULL && right == NULL)
    {
        k--;
        // (k==0)?(return root):return left;
        if (k == 0)
        {
            // k=INT_MAX;
            return root;
        }

        return left;
    }
    else if (right != NULL && left == NULL)
    {
        k--;
        // (k==0)?return root: return right;
        if (k == 0)
        {
            // k=INT_MAX;
            return root;
        }

        return right;
    }

    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *ans = ancestor(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
    // if(root->data == node)
    //     return 1;

    // int left = kthAncestor(root->left, k, node);
    // int right = kthAncestor(root->right, k, node);
}

int main(){
    
    return 0;
}