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

// pair<include node sum, exclude node sum>
pair<int, int> sum(Node* root){
    if(root == NULL)
        return (make_pair(0,0));
    
    pair<int, int> left = sum(root->left);
    pair<int, int> right = sum(root->right);
    
    //create ans pair and include and exclude current node.
    pair<int, int> ans;
    
    // exclude. --> choose max sum value of children
    ans.second = max(left.first, left.second) + max(right.first, right.second);
    
    // include. --> include current node and exclude children.
    ans.first = root->data + left.second + right.second;
    
    return ans;
    
}

int getMaxSum(Node *root) 
{
    // Add your code here
    pair<int, int> ans = sum(root);
    return max(ans.first, ans.second);
}

int main(){
    
    return 0;
}