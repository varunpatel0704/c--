#include <bits/stdc++.h>
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

void traverse(Node* root, pair<int, int>& ans, int sum, int len){
    if(root == NULL){
        if(ans.first < len){
            ans.first = max(len, ans.first);
            ans.second = sum;
        }
        
        else if(ans.first == len){
            ans.second = max(sum, ans.second);
        }
        
        return;
    }
    
    len++;
    sum+=root->data;
    traverse(root->left, ans, sum, len);
    
    
    traverse(root->right, ans, sum, len);
        
}

int sumOfLongRootToLeafPath(Node *root)
{
    //code here;
    int len = 0;
    int sum = 0;
    pair<int, int> ans = make_pair(0,0);
    traverse(root, ans, sum, len);
    
    return ans.second;
    
}

int main(){
    
    return 0;
}