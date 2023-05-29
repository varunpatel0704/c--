#include <iostream>
#include <queue>
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

void lvlorder(Node* root){
    if(root == NULL)
        return;
    queue< Node* > q; // to keep track of elements on each level 
    
    // step 1: initialize the queue by inserting root node.
    q.push(root);

    // step 2: insert left and right child of node at q.front() into the queue 
    // then pop q.front() after printing it.

    while(!q.empty()){
    

    
        if(q.front() != NULL){
            // Node* left = q.front()->left;
            // Node* right = q.front()->right;

            cout << q.front()->data << " ";
            if(q.front()->left)
                q.push(q.front()->left);

            if(q.front()->right)
                q.push(q.front()->right);
            
        q.pop();
        }
    }
    cout << "tree printed " << endl;

}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    lvlorder(root);
    return 0;
}