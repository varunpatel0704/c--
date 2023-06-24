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

bool checkbst(Node* root, int min, int max){
    if(root == NULL)
        return true;
    if(root->data >= min && root->data <= max){
        bool left = checkbst(root->left, min, root->data);
        bool right = checkbst(root->right, root->data, max);
        return left && right;
    }
    
    else
        return false;
}

bool isBST(Node* root) 
{
    // Your code here
    return checkbst(root, INT64_MIN, INT64_MAX);
}

int main(){
    
    return 0;
}