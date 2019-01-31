/**
 * Problem: Permutations of a string.
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

// Replace current node's data to sum of left and right subtrees and it's own data value.
int replaceWithSum(node* root){
    // Base case
    if(root==NULL){
        return 0;
    }
    
    
    root->data += replaceWithSum(root->left) + replaceWithSum(root->data);
    
    return root->data;
}

// Replace current node's data to sum of left and right subtrees only.
int replaceWithChildSum(node* root){
    if(root->data==NULL){
        return 0;
    }
    
    // IF this base case is not handled, leaf nodes would be having vlue 0;
    if(root->left == NULL && root->right ==NULL){
        return root->data;
    }
    
    int temp = root->data;
    root->data = replaceWithChildSum(root->left) + replaceWithChildSum(root->right);
    return temp + root->data;
}


int main() {
    node* root = NULL;
    root = buildTree();

      
	return 0;
}