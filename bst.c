#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node* left;
 struct node* right;
};
struct node* createNode(int data) {
 struct node *n; // creating a node pointer
 n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
 n->data = data; // Setting the data
 n->left = NULL; // Setting the left and right children to NULL
 n->right = NULL; // Setting the left and right children to NULL
 return n; // Finally returning the created node
}
struct node * search(struct node* root, int key){
 if(root==NULL){
 return NULL;
 }
 if(key==root->data){
 return root;
 } else if(key<root->data){
 return search(root->left, key);
 } else{
 return search(root->right, key);
 }
}
void main() {
 // 5
 // / \
 // 3 6
 // / \
 // 1 4
 struct node *p = createNode(5);
 struct node *p1 = createNode(3);
 struct node *p2 = createNode(6);
 struct node *p3 = createNode(1);
 struct node *p4 = createNode(4);
 // Linking the root node with left and right children
 p->left = p1;
 p->right = p2;
 p1->left = p3;
 p1->right = p4;
 int val;
 printf("Write a key you want to find : ");
 scanf("%d", &val);
 struct node* n = search(p, val);
 if(n!=NULL){
 printf("Found: %d", n->data);
 } else{
 printf("Element not found");
 }
}
