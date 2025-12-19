#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    //constructor
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }

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

// Node *insertHead(Node *head,int val){
//     Node *temp=new Node(val,head);
//     head=temp;
//     return head;
// }

Node *insertTail(Node *head,int val){
    Node *temp=new Node(val);
    if(head==NULL) return temp;
    Node *mover=head;
    while(mover->next!=NULL){
        mover=mover->next;
    } 
    mover->next=temp;
    return head;
}

int main(){
    vector<int> arr={7,3,2,4,5};
    Node *head=convertArr2LL(arr);
    int val;
    cout<<"Enter a value: ";
    cin>>val;
    // head=insertHead(head,val);
    // print(head);

    head=insertTail(head,val);
    print(head);
}