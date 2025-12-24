#include <bits/stdc++.h>
using namespace std;

//reversing 1D linked list using recursion
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

Node *reverse(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *newHead=reverse(head->next);
    Node *front=head->next;
    front->next=head;
    head->next=nullptr;
    return newHead;
}

int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next= new Node(3);
    head->next->next->next= new Node(4);
    head->next->next->next->next=new Node(5);

    Node *rev=reverse(head);
    while(rev){
        cout<<rev->data<<" ";
        rev=rev->next;
    }
}