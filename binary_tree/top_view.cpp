#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int d): data(d),left(nullptr),right(nullptr) {};
};

vector<int>topView(Node *root){
    vector<int>res;
    if(!root) return res;
    map<int,int>mpp;
    queue<pair<int,Node*>>q;
    q.push({0,root});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        if(mpp.find(p.first)==mpp.end()){
            mpp[p.first]=p.second->data;
        }
        if(p.second->left) q.push({p.first-1,p.second->left});
        if(p.second->right) q.push({p.first+1,p.second->right});
    }
    for(auto it:mpp){
        res.push_back(it.second);
    }
    return res;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int>res=topView(root);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}