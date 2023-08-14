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

Node *buildbst(vector<int> &preorder, int min, int max, int &index)
{
    if (index >= preorder.size())
        return NULL;
    if (preorder[index] < min || preorder[index] > max)
        return NULL;

    // if current element within range then insert here.
    Node *newnode = new Node(preorder[index++]);

    newnode->left = buildbst(preorder, min, newnode->data, index);
    newnode->right = buildbst(preorder, newnode->data, max, index);
    return newnode;
}

Node *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    Node *ans = buildbst(preorder, INT64_MIN, INT64_MAX, index);
    return ans;
}
int main(){
    
    return 0;
}