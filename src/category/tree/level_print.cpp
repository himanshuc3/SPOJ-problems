/**
 * Problem: Level order print
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


// Print specified level.
// Only 1 level printed.
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


// Returns height of tree.
int height(node* root){
    if(root==NULL){
        return 0;
    }
    
    return max(height(root->left),height(root->right))+1;
}

// Returns number of nodes in tree.
int numberOfNodes(node* root){
    if(root==NULL){
        return 0;
    }
    
    return numberOfNodes(root->left) + numberOfNodes(root->right) +1;
}


// Prints the complete tree level by level
void levelOrderPrint(node* root){
    
    int h = height(root);
    for(int i=0;i<h;i++){
        printLevel(root,i);
        cout<<endl;
    }
    
}


// Pass a series of numbers to print a binary tree.
// returns pointer to head of the tree.

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


    
 
int main() {
    node* root = NULL;
    root = buildTree();
    printLevel(root, 1);
    separator();
    cout<<numberOfNodes(root);
    separator();
    cout<<height(root);
    separator();
    levelOrderPrint(root);
    
    
    
	return 0;
}