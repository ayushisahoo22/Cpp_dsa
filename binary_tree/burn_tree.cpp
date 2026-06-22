#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left,*right;
    Node(int d): data(d),left(nullptr),right(nullptr){}
};

void markParent(Node*root,unordered_map<Node*,Node*>&mpp){
    if(!root) return;
    if(root->left){
        mpp[root->left]=root;
        markParent(root->left,mpp);
    }
    if(root->right){
        mpp[root->right]=root;
        markParent(root->right,mpp);
    }
}

Node*findNode(Node*root,int val){
    if(!root || root->data==val) return root;
    Node*lefty =findNode(root->left,val);
    if(lefty){
        return lefty;
    }
    return findNode(root->right,val);
}

int burnTree(Node*root,int val){
    if(!root) return 0;
    unordered_map<Node*,Node*>mpp;
    markParent(root,mpp);
    queue<Node*>q;
    unordered_map<Node*,bool>visited;
    Node*node=findNode(root,val);
    q.push(node);
    int time=0;
    visited[node]=true;
    while(!q.empty()){
        int s=q.size();
        time++;
        for(int i=0;i<s;i++){
            Node*temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(mpp[temp] && !visited[mpp[temp]]){
                q.push(mpp[temp]);
                visited[mpp[temp]]=true;
            }
        }
    }
    return time-1;
}

int main(){
    int val=1;
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    root->left->left->right=new Node(7);

    int time=burnTree(root,val);
    cout<<time;
    return 0;
}