/**
 * Problem: Check whether tree is balanced.
 * Top Down approach takes O(n^2) time.
 * Bottom Up approach takes O(n) time.
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

class MyPair{
    public: 
        int height;
        bool balance;
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

MyPair isHeightBalanced(node* root){
        MyPair p;
    // Base Case
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    
    // Recursive Case
    MyPair leftTree = isHeightBalanced(root->left);
    MyPair rightTree = isHeightBalanced(root->right);
    
    int diff = abs(leftTree.height-rightTree.height);
    
    if(diff<=1 && leftTree.balance && rightTree.balance){
        p.balance = true;
    }else{
        p.balance = false;
    }
    
    p.height = max(leftTree.height,rightTree.height)+1;
    return p;
}

int main() {
    node* root = NULL;
    root = buildBST(root);
    MyPair isp = isHeightBalanced(root);
    (isp.balance)?cout<<"true":cout<<"false";
    
	return 0;
}