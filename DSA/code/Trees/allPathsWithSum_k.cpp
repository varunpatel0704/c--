#include <iostream>
#include <vector>
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

void paths(Node* root, long long int targetsum, int& cnt, vector<long long int> path){
    if(root==NULL)
        return;
    path.push_back(root->data);
    paths(root->left, targetsum, cnt, path);
    paths(root->right, targetsum, cnt, path);

    long long int sum=0;
    for(int i = path.size()-1; i >= 0; i--){       
        sum+=path[i];
        if(sum==targetsum)
            cnt++;
        
    }
}
int pathSum(Node* root, int targetSum) {
    vector<long long int> path;
    int cnt=0;
    paths(root, targetSum, cnt, path);
    return cnt;
}

int main(){
    
    return 0;
}