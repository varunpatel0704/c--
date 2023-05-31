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

Node* Bst(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = Bst(root->right, data);
    }

    else    
        root->left = Bst(root->left, data);

    return root;
}

void input(Node*& root){
    int val;
    cin>>val;
    if(val!=-1)
        root = Bst(root, val);
    else    
        return;

    while(val!=-1){
        cin>>val;
        root = Bst(root, val);   
    }
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
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            Node* temp = q.front();
            q.pop();
            // Node* left = q.front()->left;
            // Node* right = q.front()->right;

            cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
            
        }
        cout<<endl;
    }
    cout << "tree printed " << endl;

}

int main(){
    Node* root = NULL;
    input(root);
    lvlorder(root);
    return 0;
}