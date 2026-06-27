#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left,*right;
    Node(int d): data(d),left(nullptr),right(nullptr){}
};

vector<int> morrisPreorder(Node*root){
    vector<int>res;
    if(!root) return res;
    Node* curr=root;
    while(curr){
        if(curr->left==NULL){
            res.push_back(curr->data);
            curr=curr->right;
        }else{
            Node*prev=curr->left;
            while(prev->right && prev->right!=curr) prev=prev->right;
            if(prev->right==NULL){
                prev->right=curr;
                res.push_back(curr->data);
                curr=curr->left;
            }else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return res;
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->right=new Node(6);

    vector<int>res=morrisPreorder(root);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}