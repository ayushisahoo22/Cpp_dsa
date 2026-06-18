#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left,*right;
    Node(int d):data(d),left(nullptr),right(nullptr){}
};

void dfs(Node*root,int key,vector<int>&res,bool &found){
    if(!root) return;
    if(root->data==key){
        res.push_back(root->data);
        found=true;
        return;
    }
    res.push_back(root->data);
    if(!found && root->left) dfs(root->left,key,res,found);
    if(!found && root->right) dfs(root->right,key,res,found);
    if(found) return;
    res.pop_back();
}
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(5);
    root->right->right->left=new Node(6);
    int key=6;
    bool found=false;
    vector<int>res;
    dfs(root,key,res,found);
    for(auto it:res){
        cout<<it<<" ";
    }
}