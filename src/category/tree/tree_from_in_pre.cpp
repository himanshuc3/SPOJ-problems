/**
 * Problem: Creating a tree from preorder and inorder traversals of tree.
 * NOTE:this is not BST, just a good old Binary tree.
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


node* createTreeFromInPre(int* pre, int* in, int low, int high){
    // i is used for iteration over preorder array and we dont want it
    // to backtrack. Therefore declared static. Could be global as well.
    static int i=0;
    if(low>high){
        return NULL;
    }
    
    // Recursive case
    node* root = new node(pre[i]);
    
    int j;
    for(j=low;j<=high;j++){
        if(in[j]==pre[i]){
            break;
        }
    }
    int element_index_in_inorder = j;
    i++;
    root->left = createTreeFromInPre(pre,in,low,element_index_in_inorder-1);
    root->right = createTreeFromInPre(pre,in,element_index_in_inorder+1,high);
    return root;
}

void preOrderPrint(node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<"->";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}





 
int main() {
    int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n=sizeof(pre)/sizeof(int);
    node* root = createTreeFromInPre(pre,in,0,n-1);
    inorderPrint(root);
	return 0;
}