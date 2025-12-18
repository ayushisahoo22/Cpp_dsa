#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    //constructor
    Node(int data1){
        data= data1;
        next= nullptr;
    }
};

Node *convertArr2LL(vector<int>arr){
    Node *head=new Node(arr[0]);
    Node *mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}

void print(Node *head){
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node *removeHead(Node *head){
    if(head==NULL) return head;
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
}

int main(){
    vector<int>arr={5,8,2,0,1};
    Node *head=convertArr2LL(arr);
    print(head);
    cout<<endl;

    //after deletion
    head=removeHead(head);
    print(head);
}