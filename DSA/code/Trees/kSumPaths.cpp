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

void solve(Node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
        return;

    path.push_back(root->data); // insert node into path

    // traverse entire tree to generate paths.
    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    // now we are returning from leaf nodes.
    // hence we have the paths ready
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
}
int sumK(Node *root, int k)
{
    // code here
    int count = 0;    // count of paths with sum equal to k.
    vector<int> path; // vector to store elements in a path.
    solve(root, k, count, path);
    return count;
}

int main(){
    return 0;
}