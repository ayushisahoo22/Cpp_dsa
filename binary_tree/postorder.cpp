#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void solve(TreeNode* root, vector<int>&res){
    if(root==NULL) return;
    solve(root->left,res);
    solve(root->right,res);
    res.push_back(root->data);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int>res;
    solve(root,res);
    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int>ans=postorderTraversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
}