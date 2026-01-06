#include <bits/stdc++.h>
using namespace std;

//Find pairs in DLL for a given sum k

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

Node *findTail(Node *head){
    Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    return temp;
}

vector<pair<int,int>> sumPairsK(Node *head,int k){
    Node* temp1=head;
    Node* temp2=findTail(head);
    vector<pair<int,int>> pairs;
    while(temp1->data<temp2->data){
        if((temp1->data+temp2->data)==k){
            pairs.push_back({temp1->data,temp2->data});
            temp1=temp1->next;
            temp2=temp2->back;
        }else if((temp1->data+temp2->data)<k){
            temp1=temp1->next;
        }else{
            temp2=temp2->back;
        }
    }
    return pairs;
}

int main(){
    vector<int> arr={1,2,3,4,9};
    Node *head=convertArr2DLL(arr);
    print(head);
    cout<<endl;
    int k;
    cout<<"Enter k: ";
    cin>>k;

    vector<pair<int,int>> result=sumPairsK(head,k);
    for(auto it:result){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
