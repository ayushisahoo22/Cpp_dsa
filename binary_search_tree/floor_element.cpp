#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left,*right;
    Node(int d):data(d),left(nullptr),right(nullptr){}
};

int floorVal(Node*root,int val){
    int floor=-1;
    while(root){
        if(val==root->data){
            floor=root->data;
            return floor;
        }
        if(root->data>val){
            root=root->left;
        }else{
            floor=root->data;
            root=root->right;
        }
    }
    return floor;
}

int main(){
    Node*root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    int val=7;
    int ans=floorVal(root,val);
    cout<<ans;
    return 0;
}