/**
 * Problem: Print kth level of a binary tree.
 * 
 */
#include<bits/stdc++.h>
using namespace std;


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


void printLevel(node* root, int level){
    if(level<0||root==NULL){
        return;
    }
    
    // Reached level.
    if(level==0){
        cout<<root->data;
        return;
    }
    
    
    printLevel(root->right,level-1);
    printLevel(root->left, level-1);
}


// Pass a series of numbers to print a binary tree.
// returns pointer to head of the tree.

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


    
 
int main() {
    node* root = NULL;
    root = buildTree();
    printLevel(root, 1);
    
    
	return 0;
}