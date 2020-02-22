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

void inorderPrint(node* root){
    if(root==NULL){
        return;
    }
    
    inorderPrint(root->left);
    cout<<root->data<<"->";
    inorderPrint(root->right);
}

node* deleteNode(node*&root, int key){
    // Base Case
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        // 1. No children
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        
        // 2. 1 Child
        if(root->left==NULL&&root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL&&root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        
        // 3. 2 Children
        // To replace the root with another node, either find the smallest node in rightSubTree
        // or find the largest node in leftSubTree
        // We are going for smallest in leftSubTree
        node* moveToRight = root->right;
        while(moveToRight->left!=NULL){
            moveToRight = moveToRight->left;
        }
        //moveToRight now has min node in leftSubTree
        // Replace root->data with moveToRight->data
        root->data = moveToRight->data;
        root->right = deleteNode(root->right,moveToRight->data);
        return root;
        
    }else if(key<root->data){
        // Important & Careless mistake. 
        // Here we have to attach the left subtree after deleting node and not just return 
        // the leftSubTree. 
        // Before I was doing: return deleteNode(root->left,key); which just returned but did not
        // attach leftSubTree because of which leftSubTree was inevitably becoming empty.
        root->left = deleteNode(root->left,key);
        return root;
    }else{
        root->right = deleteNode(root->right, key);
        return root;
    }
}

int main() {
    node* root = NULL;
    root = buildBST(root);
    inorderPrint(root);
    separator();
    root = deleteNode(root,3);
    inorderPrint(root);
    
	return 0;
}