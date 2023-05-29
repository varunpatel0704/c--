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

vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    bool direction = 1; // left to right if 1 else right to left.
    // level order traversal
    
    while(!q.empty()){
        int len = q.size();
        vector<int> temp(len);
        for(int i=0; i<len; i++){
            Node* front = q.front();
            q.pop();
            
            int index = direction?i : len-i-1; // stores elements in reverse/forward order depending on direction
            temp[index] = front->data;
            // temp[i] = front->data;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        // if(direction){
        //     for(int i=0; i<len; i++){
        //         ans.push_back(temp[i]);
        //     }
        // }
        // else{
        //     for(int i=len-1; i>=0; i--){
        //         ans.push_back(temp[i]);
        //     }
        // }
        for(auto i: temp)
            ans.push_back(i);
            
        direction = !direction;
    }
    
    return ans;
    
}

int main(){
    
    return 0;
}