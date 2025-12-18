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

int main(){
    vector<int>arr={3,7,1,8};
    Node *head=convertArr2LL(arr);
    cout<<head->data<<" "<<head->next;
}