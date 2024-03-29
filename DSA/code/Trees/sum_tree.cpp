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

pair<int, bool> sumtree(Node* root){
    if(root == NULL){
        pair<int, bool> p = make_pair(0, true); //null node is always a sumTree
        return p;
    }
    
    if(root->left == NULL && root->right == NULL){
        pair<int, bool> p = make_pair(root->data, true);
        return p;
    }
    pair<int, bool> left = sumtree(root->left);
    pair<int, bool> right = sumtree(root->right);
    
    pair<int, bool> ans;
    
    
    if(root->data == left.first+right.first && left.second && right.second){ // if the sum of current node = 
        ans.second = true;                                                   // sum of left and right subtrees, then proceed
        ans.first = left.first + right.first + root->data; // <-- sum of entire subtree including the root node, will be returned.
    }
    else
        ans.second = false;
    
    return ans;
}

bool isSumTree(Node* root)
{
    return sumtree(root).second;
}

int main(){
    
    return 0;
}