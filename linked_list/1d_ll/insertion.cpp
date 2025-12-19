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

// Node *insertTail(Node *head,int val){
//     Node *temp=new Node(val);
//     if(head==NULL) return temp;
//     Node *mover=head;
//     while(mover->next!=NULL){
//         mover=mover->next;
//     } 
//     mover->next=temp;
//     return head;
// }

// Node *insertPos(Node *head,int pos,int val){
//     if(head==NULL){
//         if(pos==1){
//             Node *temp=new Node(val);
//             return temp;
//         }
//         else{
//             return head;
//         }
//     }
//     if(pos==1){
//         Node *temp=new Node(val,head);
//         head=temp;
//         return temp;
//     }
//     Node *n=new Node(val);
//     Node *mover=head;
//     int cnt=0;
//     while(mover){
//         cnt++;
//         if(cnt==pos-1){
//             n->next=mover->next;
//             mover->next=n;
//             break;
//         }
//         mover=mover->next;
//     }
//     return head;
// }

Node *insertBeforeEl(Node *head,int el,int val){
    if(head==NULL){
        return head;
    }
    if(head->data==el){
        Node *temp=new Node(val,head);
        head=temp;
        return temp;
    }
    Node *n=new Node(val);
    Node *mover=head;
    while(mover!=NULL){
        if(mover->next->data==el){
            n->next=mover->next;
            mover->next=n;
            break;
        }
        mover=mover->next;
    }
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

    // head=insertTail(head,val);
    // print(head);

    // int pos;
    // cout<<"Enter position: ";
    // cin>>pos;
    // head=insertPos(head,pos,val);
    // print(head);

    int el;
    cout<<"Enter element: ";
    cin>>el;
    head=insertBeforeEl(head,el,val);
    print(head);
}