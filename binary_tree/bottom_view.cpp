#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left,*right;
    Node(int d):data(d),left(NULL),right(NULL){};
};

vector<int>bottomView(Node*root){
    vector<int>res;
    if(!root) return res;
    queue<pair<Node*,int>>q;
    map<int,int>mpp;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        mpp[p.second]=p.first->data;
        if(p.first->left) q.push({p.first->left,p.second-1});
        if(p.first->right) q.push({p.first->right,p.second+1});
    }
    for(auto it:mpp){
        res.push_back(it.second);
    }
    return res;
}

int main(){
    Node *root= new Node(3);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int>res=bottomView(root);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}