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
    res.push_back(root->data);
    solve(root->left,res);
    solve(root->right,res);
}
vector<int> preorderTraversal(TreeNode* root) {
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
    vector<int>ans=preorderTraversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
}