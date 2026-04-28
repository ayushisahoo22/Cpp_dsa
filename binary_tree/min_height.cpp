#include<bits/stdc++.h>
using namespace std;

//LC-111
struct Node{
    int data;
    struct Node* left,*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

int minDepth(Node* root) {
        if(root==NULL) return 0;
        int right=minDepth(root->right);
        int left=minDepth(root->left);

        //edge case-for right/left skewed
        if(left==0 || right==0){
            return 1+max(left,right);
        }
        return 1+min(left,right);
    }

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int ans=minDepth(root);
    cout<<ans;
}