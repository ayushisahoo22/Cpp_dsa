#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

int maxNode(Node* root){
    while(root->left){
        root=root->left;
    }
    return root->data;
}

int minNode(Node* root){
    while(root->right){
        root=root->right;
    }
    return root->data;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);
    
    int maxi=maxNode(root);
    int mini=minNode(root);
    cout<<maxi<<" " <<mini;

    return 0;
}