#include<bits/stdc++.h>
using namespace std;

//length of linked list

class Node{
public:
    int data;
    Node* next;

    //constructor
    Node(int x){
        data=x;
        next=nullptr;
    }

    //constructor
    Node(int x,Node *next1){
        data=x;
        next=next1;
    }
};

int lengthLoop(Node *head){
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int cnt=1;
            fast=fast->next;
            while(fast!=slow){
                cnt++;
                fast=fast->next;
            }
            return cnt;
        }
    }
    return 0;
}

int main(){
    // Create nodes
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);

    // Create a cycle: connect tail to index 1 node (value 2)
    head->next->next->next->next = head->next;

    int len=lengthLoop(head);
    cout<<len;
}