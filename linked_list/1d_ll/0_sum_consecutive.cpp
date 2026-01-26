#include<bits/stdc++.h>
using namespace std;

// task is to repeatedly remove consecutive sequences of nodes that sum to 0 
// and occur first in the singly linked list until there are no such sequences.

class linkedListNode{
public:
    int data;
    linkedListNode* next;
    linkedListNode(int val){
        data=val;
        next=nullptr;
    }
};

linkedListNode *convertArr2LL(vector<int>arr){
    linkedListNode *head=new linkedListNode(arr[0]);
    linkedListNode *mover=head;
    for(int i=1;i<arr.size();i++){
        linkedListNode *temp=new linkedListNode(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}

linkedListNode *zeroConsecutiveDel(linkedListNode* head){
    linkedListNode* dummy= new linkedListNode(0);
    dummy->next=head;
    unordered_map<int,linkedListNode*>mpp;
    mpp[0]=dummy;
    int prefixSum=0;
    linkedListNode *curr=head;
    while(curr){
        prefixSum+=curr->data;
        if(mpp.count(prefixSum)){
            linkedListNode *prev=mpp[prefixSum];
            linkedListNode *temp=prev->next;
            int sum=prefixSum;
            while(temp!=curr){
                sum+=temp->data;
                mpp.erase(sum);
                temp=temp->next;
            }
            prev->next=curr->next;
        }else{
            mpp[prefixSum]=curr;
        }
        curr=curr->next;
    }
    return dummy->next;
}

int main(){
    vector<int>arr={-2,4,-2,1};
    linkedListNode *head=convertArr2LL(arr);
    head=zeroConsecutiveDel(head);
    linkedListNode *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
