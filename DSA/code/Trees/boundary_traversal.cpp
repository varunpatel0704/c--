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

void leftside(Node *root, vector<int> &left)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;
    left.push_back(root->data);
    if (root->left)
        leftside(root->left, left);
    else
        leftside(root->right, left);
}

void rightside(Node *root, vector<int> &right)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    if (root->right)
        rightside(root->right, right);
    else
        rightside(root->left, right);

    right.push_back(root->data);
}

void leafnodes(Node *root, vector<int> &leaf)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        leaf.push_back(root->data);
        return;
    }

    leafnodes(root->left, leaf);
    leafnodes(root->right, leaf);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    leftside(root->left, ans);

    leafnodes(root->left, ans);
    leafnodes(root->right, ans);

    rightside(root->right, ans);

    return ans;
}

int main(){
    
    return 0;
}