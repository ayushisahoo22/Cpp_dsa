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

Node *deleteTail(Node *head){
    if(head==NULL || head->next==NULL) return NULL;
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->back->next=nullptr;
    delete temp;
    return head;
}

Node *deleteK(Node *head,int k){
    if(head==NULL) return NULL;
    Node *temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    Node *prev=temp->back;
    Node *front=temp->next;
    if(prev==NULL && front==NULL){
        delete temp;
        return head;
    }else if(prev==NULL){
        return deleteHead(head);
    }else if(front==NULL){
        return deleteTail(head);
    }
    prev->next=front;
    front->back=prev;
    delete temp;
    return head;
}

Node *deleteVal(Node *head,int val){
    if(head==NULL) return NULL;
    Node *temp=head;
    while(temp){
        if(temp->data==val){
            break;
        }
        temp=temp->next;
    }
    if(temp->back==NULL){
        head=temp->next;
        if(head!=NULL){
            head->back=nullptr;
        }
    }else{
        temp->back->next=temp->next;
        if(temp->next!=NULL){
            temp->next->back=temp->back;
        }
    }
    delete temp;
    return head;
}

int main(){
    vector<int>arr={2,5,7,3,1,8};
    Node *head=convertArr2DLL(arr);
    print(head);
    cout<<endl;

    //Deletion of head
    // head=deleteHead(head);
    // print(head);

    //Deletion of tail
    // head=deleteTail(head);
    // print(head);

    //Deletion of Kth element
    // int k;
    // cout<<"Enter k: ";
    // cin>>k;
    // head=deleteK(head,k);
    // print(head);

    //Deletion of value
    int val;
    cout<<"Enter value: ";
    cin>>val;
    head=deleteVal(head,val);
    print(head);
}