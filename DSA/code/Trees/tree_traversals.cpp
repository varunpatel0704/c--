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

void inorder(Node* root){
    // inorder follows LNR
    if(root == NULL)
        return;
    
    // go left.         
    inorder(root->left);

    // print node.
    cout << root->data << " ";

    // go right.
    inorder(root->right);
}

void preorder(Node* root){
    // preorder follows NLR
    if(root == NULL)
        return;

    // print node.
    cout << root->data << " ";

    // go left.
    preorder(root->left);

    // go right.
    preorder(root->right);
}

void postorder(Node* root){
    // postorder follows LRN
    if(root == NULL)
        return;
    
    // go left
    postorder(root->left);

    // go right
    postorder(root->right);

    // print node.
    cout << root->data << " ";
}

Node* buildTree(Node* root){
    // take data as input
    int data;
    cout <<"Enter value for the node: ";
    cin >> data;

    // base case: 
    if(data == -1){
        return root;
    }
    
    root = new Node(data);

    // repeat process for left and right child.
    cout << "Enter data for left child of " << data << endl;
    root->left = buildTree(root->left);
    
    cout << "Enter data for right child of " << data <<endl;
    root->right = buildTree(root->right);

    return root;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    fflush(stdin);
    cout << endl << "inorder traversal: ";
    inorder(root);
    cout << endl << "preorder traversal: ";
    preorder(root);
    cout << endl << "postorder traversal: ";
    postorder(root);
    return 0;
}