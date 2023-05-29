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

vector<int> leftView(Node *root)
{
// Your code here
    queue<Node*> q;
    vector<int> ans;
    if(root==NULL)
        return ans;
    q.push(root);
    while(!q.empty()){
        int len = q.size();
        for(int i=0; i<len; i++){
            Node*front=q.front();
            q.pop();
            if(i==len-1) // replace len-1 with 0 to get left view of binary tree.
                ans.push_back(front->data);
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
    }
    return ans;
}

int main(){
    
    return 0;
}