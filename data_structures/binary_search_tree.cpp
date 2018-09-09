#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int d;
    node* left;
    node* right;
    node(int data){
    d = data;
    left = NULL;
    right = NULL;
  }
};

class LinkedList{
    public:
        node* head;
        node*tail;
}

LinkedList flatten(node*root){
    LinkedList l;
    if(root==NULL){
        l.head= l.tail = NULL;
    }
    //leaf node
    if(root->left==NULL&&root->right==NULL){
        l.head=l.tail = root;
        return l;
    }
    //left is not NULL
    if(root->left!=NULL&&root->right==NULL){
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;
        
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    //Right is not NULL
    if(root->left==NULL&&root->right!=NULL){
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;
        
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    //Both sides are not NULL
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);
    
    leftLL.tail->right = root;
    root->right = rightLL.head;
    
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
    
}

node* deleteInBST(node* root, int d){
    if(root==NULL){
        return NULL;
    }
    else if(d<root->d){
        root->left = deleteInBST(root->left,data);
        return root;
    }else if(d==root->d){
        //found the node to delete
        //3 cases
        //1. Node with 0 children
        if(root->left==NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //2. Only 1 children
        if(root->left!=NULL&&root->right==NULL){
            node*temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL&&root->right!=NULL){
            node*temp = root->right;
            delete root;
            return temp;
        }
        //3. Two children
        node* replace = root->right;
        //find the inorder successor of right subtree
        while(replace->left!=NULL){
            replace = replace->left;
        }
        root->d = replace->d;
        root->right = deleteInBST(root->right,replace->d);
    }else{
        root->right = deleteInBST(root->right, d);
        return root;
    }
}
node* insertInBST(node* root,int d){
    if(root==NULL){
        return new node(d);
    }
    if(data<=root->d){
        root->left = insertInBST(root->left,d);
    }else{
        root->right = insertInBST(root->right,d);
    }
    return root;
}

bool search(node* root,int d){
    if(root==NULL){
        return false;
    }
    if(d==root->d){
        return true;
    }else if(d<root->d){
        return search(root->left,d);
    }else{
        return search(root->right,d);
    }
}

bool isBST(node* root, int minV = INT_MIN, int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->d >=minV && root->d <=maxV && isBST(root->left,minV,root->d)&&isBST(root->right,root->d,maxV)){
        return true;
    }
    return false;
}
node* build(){
    //Read a list of numbers till -1 and also these numbers
    //will be inserted into BST
    int d;
    cin>>d;
    
    node*root = NULL;
    
    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}

int main(){
    node* root = NULL;
    
}