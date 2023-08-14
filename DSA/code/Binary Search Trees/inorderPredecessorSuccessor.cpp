#include <iostream>
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

pair<int,int> predecessorSuccessor(Node* root, int key)
{
    // Write your code here.
    int pred = -1, succ = -1;
    pair<int, int> ans;
    Node*temp = root;

    while(temp->data != key){
        if(key > temp->data){
            pred = temp->data;
            temp = temp->right;
        }
        else{
            succ = temp->data;
            temp = temp->left;
        }
    }
    Node*leftTree = temp->left, *rightTree = temp->right;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    ans.first = pred, ans.second = succ;
    return ans;
}

int main(){
    
    return 0;
}