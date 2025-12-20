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

Node *deleteHead(Node *head){
    if(head==NULL || head->next==NULL) return NULL;
    Node *temp=head;
    head=head->next;
    head->back=nullptr;
    delete temp;
    return head;
}

int main(){
    vector<int>arr={2,5,7,3,1,8};
    Node *head=convertArr2DLL(arr);
    print(head);
    cout<<endl;

    //Deletion of head
    head=deleteHead(head);
    print(head);
}