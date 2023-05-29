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

void lvlordertraversal(Node* root){
    queue <Node*> q;
    q.push(root);

    while(!q.empty()){
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            Node* temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }

}

void levelorder(Node* &root){
    // we will create a tree level wise instead of conventional way
    
    // using queue to track the elements. Initialize it with root node
    cout << "Enter data for root: ";
    int rootdata;
    cin >> rootdata;
    if(rootdata!=-1)
        root = new Node(rootdata);
    queue <Node*> q;
    q.push(root);

    // process till q is not empty.
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        // insert left and right children of front element into q
        cout << "Enter data for left child of " << temp->data << ": ";
        int val;
        cin >> val;
        if(val != -1){
            temp->left = new Node(val);
            q.push(temp->left);
        }
        cout << "Enter data for right child of " << temp->data << ": ";
        cin >> val;
        if(val != -1){
            temp->right = new Node(val);
            q.push(temp->right);
        }
        
    }
    
}

int main(){
    Node* root = NULL;
    levelorder(root);
    lvlordertraversal(root);
    return 0;
}