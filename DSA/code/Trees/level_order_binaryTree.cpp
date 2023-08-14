#include <iostream>
#include <vector>
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

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;
    queue<Node*> q;

    // initialize the queue with root node.
    q.push(root);

    while(!q.empty()){
        // process the tree level-wise
        // to do that, run a for loop for the number 
        // of nodes currently in the queue because they basically represent a level.
        int len = q.size();
        vector<int> result;

        for(int i=0; i<len; i++){
            // remove the node at q front and store 
            // its children in the queue if non null
            Node* temp = q.front();
            q.pop();
            result.push_back(temp->data);                
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        // append the result(level) into ans
        ans.push_back(result);
    }
    return ans;
}

int main(){
    
    return 0;
}