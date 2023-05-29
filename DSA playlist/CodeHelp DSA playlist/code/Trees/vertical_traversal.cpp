#include <iostream>
#include <map>
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

void verticaltraversal(Node* root, map<int, vector<int>>& store, int index){
    // if(root == NULL)
    //     return;
    
    // verticaltraversal(root->left, store, index-1);
    
    // store[index].push_back(root->data);
    
    // verticaltraversal(root->right, store, index+1);
    
    queue<pair<Node*, int>> q; // queue of pairs. Each pair stores a node and its corresponding index in the map
    pair<Node*, int> p = make_pair(root, index);
    q.push(p); // initialize queue with first pair.
    
    while(!q.empty()){
        int len = q.size();
        for(int i = 0; i<len; i++){
            
            pair<Node*, int> temp = q.front(); // since queue stores pairs.
            q.pop();
            
            store[temp.second].push_back(temp.first->data); // first block of queue stores Node
                                                            // second block stores index 
            if(temp.first->left){
                pair<Node*, int> p = make_pair(temp.first->left, temp.second-1);
                q.push(p);
            }
            
            if(temp.first->right){
                pair<Node*, int> p = make_pair(temp.first->right, temp.second+1);
                q.push(p);
            }
            
        }
    }
}

vector<int> verticalOrder(Node *root)
{
    map<int, vector<int>> store;
    vector<int> ans;
    int index = 0;
    // store[index].push_back(root->data);
    verticaltraversal(root, store, index);
    // verticaltraversal(root->right, store, index+1);
    for(auto i: store){ // transferring elements from map into ans array.
        for(auto j: i.second){ // map stores index values in sorted order i.e. elements corresponding
            ans.push_back(j);  //  to smaller index will be inserted first into the vector
        }
    }
    return ans;
}

vector<int> topView(Node *root) // top view of a binary tree.
{
    //Your code here
    vector<int> ans;
    map<int, vector<int>> store;
    int index = 0;
    // store[index].push_back(root->data);
    verticaltraversal(root, store, index);
    for(auto i: store){
        ans.push_back(i.second[0]); // replace second[0] with second[second.size()-1] to get bottom view
    }
    return ans;
}

int main(){
    
    return 0;
}