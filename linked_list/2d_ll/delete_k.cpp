#include <bits/stdc++.h>
using namespace std;

//Delete k from the linkedlist and return head

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

Node *deletingK(Node *head,int k){
    Node *temp=head;
    while(temp){
        if(temp->data==k){
            if(temp==head){
                head=head->next;
            }
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
    vector<int> arr={0,7,2,0,1,0};
    Node *head=convertArr2DLL(arr);
    print(head);
    cout<<endl;
    int k;
    cout<<"Enter k: ";
    cin>>k;

    //after deleting
    head=deletingK(head,k);
    print(head);
}