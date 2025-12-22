#include<bits/stdc++.h>
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

    //constructor
    Node(){
        data=0;
        next=nullptr;
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
    if(head==NULL) return;
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//TC->O(N+M)   SC->0(N+M)
Node *insertEnd(Node *head,int value){
    Node *n=new Node(value);
    if(head==NULL) return n;
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return head; 
}

Node* mergeTwoLists(Node* list1, Node* list2) {
    Node *i=list1;
    Node *j=list2;
    Node *result=NULL;
    while(i!=NULL && j!=NULL){
        if(i->data<=j->data){
            result=insertEnd(result,i->data);
            i=i->next;
        }else{
            result=insertEnd(result,j->data);
            j=j->next;
        }
    }
    while(i!=NULL){
        result=insertEnd(result,i->data);
        i=i->next;
    }
    while(j!=NULL){
        result=insertEnd(result,j->data);
        j=j->next;
    }
    return result;
}

int main(){
    int n,m;
    cout<<"Enter n for list1: ";
    cin>>n;
    vector<int>arr1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr1.push_back(x);
    }
    cout<<"Enter m for list2: ";
    cin>>m;
    vector<int>arr2;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        arr2.push_back(x);
    }
    Node *list1=convertArr2LL(arr1);
    Node *list2=convertArr2LL(arr2);
    Node *result=mergeTwoLists(list1,list2);
    print(result);
}