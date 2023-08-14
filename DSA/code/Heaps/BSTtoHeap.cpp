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

void printTree(Node* root){
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            Node* front = q.front();
            q.pop();

            cout << front->data << " ";

            if(front->left){
                q.push(front->left);
            }
        
            if(front->right){
                q.push(front->right);
            }
        } 
        cout<<endl;
    }
}

// creating bst using levelorder
Node* buildBst(Node* root){
    cout<<"Enter the value of root node: ";
    int val;
    cin>>val;
    if(val != -1);
    root = new Node(val);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout << "Enter the value for the left child of " << front->data << ": ";
        cin >> val;
        if(val!=-1){
            front->left = new Node(val);
            q.push(front->left);
        }
        cout << "Enter the value for the right child of " << front->data << ": ";
        cin>>val;
        if(val!=-1){
            front->right = new Node(val);
            q.push(front->right);
        }
    }
    return root;
}

Node* createBst(Node*& root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = createBst(root->right, data);
    }

    else    
        root->left = createBst(root->left, data);

    return root;
}
void input(Node*& root){
    int val;
    cin>>val;
    if(val!=-1)
        root = createBst(root, val);
    else    
        return;

    while(true){
        cin>>val;
        if(val != -1)
            root = createBst(root, val);   
        else    
            break;
    }
}


void traversal(Node* root, vector<int>& inorder){
	if(root == NULL)
		return;
	
	traversal(root->left, inorder);

	inorder.push_back(root->data);
	
	traversal(root->right, inorder);
}

void bstToHeap(Node* &root, vector<int>& inorder, int& index){
	// traverse in preorder fashion and replace node values with that of inorder.
	if(root == NULL || index >= inorder.size())
		return;

	root->data = inorder[index++];

	bstToHeap(root->left, inorder, index);
	bstToHeap(root->right, inorder, index);

}

Node* convertBST(Node*& root)
{
	// step 1: get inorder traversal of binary tree.
	vector<int> inorder;
	traversal(root, inorder);

	// step 2: convert bst into heap by traversing in preorder fashion and
	// replacing the data of nodes with that of inorder.
	int index = 0;
	bstToHeap(root, inorder, index);

	return root;
}

int main(){
    Node* root = NULL;
    createBst(root, 4);
    createBst(root, 2);
    createBst(root, 6);
    createBst(root, 1);
    createBst(root, 3);
    createBst(root, 5);
    createBst(root, 7);
    // input(root);
    // root = buildBst(root);
    cout << "printing tree..."<<endl;
    printTree(root);

    convertBST(root);
    cout << "printing tree after bst to min heap" << endl;
    printTree(root);
    return 0;
}