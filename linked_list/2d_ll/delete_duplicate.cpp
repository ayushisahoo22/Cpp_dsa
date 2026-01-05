#include <bits/stdc++.h>
using namespace std;

//Delete duplicates from the sorted linkedlist and return head

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

Node *deletingduplicate(Node *head){
    Node *temp=head->next;
    while(temp){
        if(temp->data==temp->back->data){
            Node *nextNode=temp->next;
            Node *prevNode=temp->back;
            if(nextNode) nextNode->back=prevNode;
            if(prevNode) prevNode->next=nextNode;
            delete temp;
            temp=nextNode;
        }else{
            temp=temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr={0,0,1,2,3,3};
    Node *head=convertArr2DLL(arr);
    print(head);
    cout<<endl;

    //after deleting
    head=deletingduplicate(head);
    print(head);
}