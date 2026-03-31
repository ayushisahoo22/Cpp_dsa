#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left,*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

int maxDepth(Node *root){
    if(!root) return 0;
    int maxLeft=maxDepth(root->left);
    int maxRight=maxDepth(root->right);
    return max(maxLeft,maxRight)+1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int ans=maxDepth(root);
    cout<<ans;
}
