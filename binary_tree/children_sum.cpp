#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left,*right;
    Node(int d):data(d),left(nullptr),right(nullptr){}
};

void childrenSum(Node *root){
    if(!root) return;
    int child=0;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }
    if(child>=root->data) root->data=child;
    else{
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }
    childrenSum(root->left);
    childrenSum(root->right);
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data=tot;
}

void printTree(Node*root){
    if(!root) return;
    cout<<root->data<<" ";
    if(root->left) printTree(root->left);
    if(root->right) printTree(root->right);
}

int main(){
    Node *root=new Node(50);
    root->left=new Node(7);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(5);
    root->right->left=new Node(1);
    root->right->right=new Node(30);

    childrenSum(root);
    printTree(root);
    return 0;
}