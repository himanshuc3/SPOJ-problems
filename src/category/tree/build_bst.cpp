/**
 * Problem: Replace with sum of subtrees.
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


node* insertInBST(node* root, int data){
    // Base Case
    if(root==NULL){
        root = new node(data);
        return root;
    }
    // Recursive case
    if(data<root->data){
        root->left = insertInBST(root->left,data);
    }else{
        root->right = insertInBST(root->right,data);
    }
    return root;
    
    
}


node* buildBST(node*&root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertInBST(root,data);
        cin>>data;
    }
    return root;
    
}

bool searchInBST(node* root, int data){
    if(root==NULL){
        return false;
    }
    
    if(root->data==data){
        return true;
    }else if(data<root->data){
        return searchInBST(root->left, data);
    }else{
        return searchInBST(root->right, data);
    }
}

int main() {
    node* root = NULL;
    root = buildBST(root);
    bool is = searchInBST(root, 3);
    (is)?cout<<"true":cout<<"false";
	return 0;
}