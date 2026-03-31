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

int height(Node *root){
    if(!root) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

bool isBalanced(Node *root){
    if(!root) return true;
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    if(abs(leftHeight-rightHeight)>1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}