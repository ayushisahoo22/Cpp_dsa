#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left,*right;
    Node(int d):data(d),left(nullptr),right(nullptr){}
};

int findS(Node* root,int k){
    int s = -1;
    while(root){
        if(root->data<=k){
            root=root->right;
        }else{
            s=root->data;
            root=root->left;
        }
    }
    return s;
}

int findP(Node*root,int k){
    int p=-1;
    while(root){
        if(root->data>=k){
            root=root->left;
        }else{
            p=root->data;
            root=root->right;
        }
    }
    return p;
}

pair<int,int>findPS(Node*root,int key){
    if(!root) return {};
    int successor=findS(root,key);
    int predecessor=findP(root,key);
    return {predecessor,successor};
}

int main(){
    Node *root=new Node(5);
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->left->right->left=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(9);
    root->right->right->left=new Node(8);
    root->right->right->right=new Node(10);
    int key=7;
    pair<int,int>p=findPS(root,key);
    cout<<p.first<<" "<<p.second;
    return 0;
}