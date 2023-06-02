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


Node* createBst(Node* root, int data){
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

bool searchInBST(Node *root, int x) {
    if(root == NULL)
        return false;
    
    if(root->data == x)
        return true;

    
    else if(x > root->data){
        return searchInBST(root->right, x);
    }
        
    else    
        return searchInBST(root->left, x);
}

bool searchBst(Node* root, int data){
    // iterative solution; without using any extra space.
    while(root != NULL){
        if(root->data == data)
            return true;
        
        if(data > root->data)
            root = root->right;
        else    
            root = root->left;
    }
    return false;
}

Node* get_successor(Node* root){
    while(root->left !=NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int nodeToDel)
{
    //base case.
    if(root == NULL)
        return root;
    
    
    if(root->data == nodeToDel){
        
        // 0 children.
        if(root->left == NULL && root->right == NULL){
            // simply delete the node and return.
            delete root;
            return NULL; // NULL will be returned to previous call and new child of that node will be NULL.
        }

        // 1 child.
        // only left child exists.
        if(root->left != NULL && root->right == NULL){
            // temporarily store the child node since we will delete the parent(current) node.
            Node* temp = root->left;
            delete root;
            return temp; // left child of the deleted node will be returned and linked to previous node. 
        }

            // only right child exists.
        if(root->right != NULL && root->left == NULL){
            // temporarily store the child node since we will delete the parent(current) node.
            Node* temp = root->right;
            delete root;
            return temp; // right child of the deleted node will be returned and linked to previous node. 
        }

        // 2 children.
        if(root->left != NULL && root->right != NULL){
            // replace the value of node with either inorder successor or predecessor
            Node* successor = get_successor(root->right); // find inorder successor (which is present on right side.)
            root->data = successor->data;

            // now find and delete successor.
            root->right = deleteNode(root->right, successor->data);
            return root;
        }

    }

    else if(nodeToDel > root->data){  
        root->right = deleteNode(root->right, nodeToDel);
        return root;
    }

    else{
        root->left = deleteNode(root->left, nodeToDel);
        return root;
    }
    
}

void lvlorder(Node* root){
    if(root == NULL)
        return;
    queue< Node* > q; // to keep track of elements on each level 
    
    // step 1: initialize the queue by inserting root node.
    q.push(root);

    // step 2: insert left and right child of node at q.front() into the queue 
    // then pop q.front() after printing it.

    while(!q.empty()){
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            Node* temp = q.front();
            q.pop();
            // Node* left = q.front()->left;
            // Node* right = q.front()->right;

            cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
            
        }
        cout<<endl;
    }
    cout << "tree printed " << endl;

}

int main(){
    Node* root = NULL;
    input(root);
    lvlorder(root);

    deleteNode(root, 50);
    cout<<"After deletion: "<<endl;
    lvlorder(root);
    return 0;
}