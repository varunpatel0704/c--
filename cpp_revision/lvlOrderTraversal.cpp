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
Node* buildtree(Node* root){
    // take the input value for root node/current node.
    cout<<"Enter Value for node: ";
    int val;
    cin>>val;
    if( val != -1 )
        root= new Node(val);
    else    
        return NULL;
    
    cout<<"Enter Value for left child of "<<root->data<<endl;
    root->left = buildtree(root->left);

    cout<<"Enter Value for right child of "<<root->data<<endl;
    root->right = buildtree(root->right);

    return root;
}
void lvlOrderTraversal(Node* root){
    // initialize q with root node.
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        // traverse the tree level wise. 
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            Node* temp = q.front();
            q.pop();

            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        cout<<endl;
        
    }
}
int main(){
    Node* root=buildtree(root);
    lvlOrderTraversal(root);
    return 0;
}