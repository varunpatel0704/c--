#include <vector>
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

/* Alternate solution (without using vector) 

void solve(Node *root, int k, int &index, int &ans)
{
    if (root == NULL)
        return;

    solve(root->left, k, index, ans);

    index++;
    if (index == k)
        ans = root->data;

    solve(root->right, k, index, ans);
}

int kthSmallest(Node *root, int k)
{
    int ans = -1;
    int index = 0;
    solve(root, k, index, ans);
    return ans;
} */

void solve(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    solve(root->left, inorder);

    inorder.push_back(root->data);

    solve(root->right, inorder);
}

int kthSmallest(Node *root, int k)
{
    vector<int> inorder;
    solve(root, inorder);
    return inorder[k - 1];
}

int main(){
    
    return 0;
}