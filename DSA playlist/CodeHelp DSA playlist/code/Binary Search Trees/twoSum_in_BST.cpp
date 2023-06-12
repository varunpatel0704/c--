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

bool findTarget(Node *root, int k)
{
    vector<int> inorder;
    traversal(root, inorder);
    int i = 0, j = inorder.size() - 1;
    int sum = 0;
    while (i < j)
    {
        sum = inorder[i] + inorder[j];

        // this logic is similar to binary search.
        // find the sum and compare with k.
        // use start and end (i and j).
        if (sum == k)
            return true;

        // sum > k implies we want a smaller sum to match k.
        else if (sum > k)
            j--;

        // sum < k implies we need a larger sum to match k.
        else
            i++;
    }

    return false;
}

int main(){
    
    return 0;
}