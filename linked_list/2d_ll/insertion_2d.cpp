#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *back;

    //constructor
    Node(int data1){
        data= data1;
        next= nullptr;
        back=nullptr;
    }

    //constructor
    Node(int data1,Node *next1,Node *back1){
        data=data1;
        next=next1;
        back=back1;
    }
};

Node *convertArr2DLL(vector<int>arr){
    Node *head=new Node(arr[0]);
    Node *mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i],nullptr,mover);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}

void print(Node *head){
    if(head==NULL) return;
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node *insertHead(Node *head,int val){
    if(head==NULL){
        Node *temp=new Node(val);
        head=temp;
        return head;
    }
    Node *temp=new Node(val,head,nullptr);
    head->back=temp;
    head=temp;
    return head;
}

Node *insertTail(Node *head,int val){
    if(head==NULL){
        Node *temp=new Node(val);
        head=temp;
        return head;
    }
    Node *temp=new Node(val);
    Node *mover=head;
    while(mover->next!=NULL){
        mover=mover->next;
    }
    mover->next=temp;
    temp->back=mover;
    return head;
}

Node *insertBefTail(Node *head,int val){
    if(head==NULL){
        Node *temp=new Node(val);
        head=temp;
        return head;
    }
    Node *temp=new Node(val);
    Node *mover=head;
    while(mover->next->next!=NULL){
        mover=mover->next;
    }
    temp->next=mover->next;
    mover->next=temp;
    temp->back=mover;
    temp->next->back=temp;
    return head;
}

int main(){
    vector<int>arr={2,5,7,3,1,8};
    Node *head=convertArr2DLL(arr);
    print(head);
    cout<<endl;
    int val;
    cout<<"Enter value: ";
    cin>>val;

    //Insertion at head
    // cin>>val;
    // head=insertHead(head,val);
    // print(head);

    //Insertion at tail
    // head=insertTail(head,val);
    // print(head);

    //Insertion before tail 
    head=insertBefTail(head,val);
    print(head);
}