/**
 * Problem: Different patterns of traversing a tree.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// node class 
// Ideally, other methods should be either in this class
// or tree class using node class.
class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
};


void separator(){
    cout<<endl<<"==================="<<endl;
    cout<<"==================="<<endl;
}

node* buildTree(){
    int data;
    cin>>data;
    
    // node is NULL if data = -1;
    if(data==-1){
        return NULL;
    }
    
    node* n = new node(data);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void inorderPrint(node* root){
    if(root==NULL){
        return;
    }
    
    inorderPrint(root->left);
    cout<<root->data<<"->";
    inorderPrint(root->right);
}

void preOrderPrint(node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<"->";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

void postOrderPrint(node* root){
    if(root==NULL){
        return;
    }
    
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout<<root->data<<"->";
}

    
 
int main() {
    node* root = NULL;
    root = buildTree();
    separator();
    levelOrderPrint(root);
    separator();
    inorderPrint(root);
    separator();
    postOrderPrint(root);
    separator();
    preOrderPrint(root);
    
    
	return 0;
}