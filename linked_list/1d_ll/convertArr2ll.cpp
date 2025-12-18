#include <bits/stdc++.h>
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

//To find lenght of linked list
int lengthLL(Node *head){
    int cnt=0;
    Node *temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

//To search an element
int isPresent(Node *head,int x){
    Node *temp=head;
    while(temp){
        if(temp->data==x) return 1;
        temp=temp->next;
    }
    return 0;
} 

int main(){
    vector<int>arr={3,7,1,8};
    Node *head=convertArr2LL(arr);
    cout<<head->data<<" "<<head->next<<endl;

    //traversal
    Node *ptr=head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<"\n";

    int length=lengthLL(head);
    cout<<length<<endl;

    int found1=isPresent(head,1);
    cout<<found1<<endl;

    int found2=isPresent(head,2);
    cout<<found2<<endl;
}