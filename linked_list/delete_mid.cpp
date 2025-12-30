#include<bits/stdc++.h>
using namespace std;

//find middle of linked list
//by tortoise hare algo
//delete it
//TC->O(N)   SC->O(1)

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

Node *delMiddleNode(Node *head){
    Node *tortoise=head;
    Node* hare=head;
    //as we need a slow step behind so hare will more early
    hare=hare->next->next;
    while(hare!=NULL && hare->next!=NULL){
        tortoise=tortoise->next;
        hare=hare->next->next;
    }
    Node *del=tortoise->next;
    tortoise->next=tortoise->next->next;
    delete del;
    return head;
}

int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next= new Node(3);
    head->next->next->next= new Node(4);
    head->next->next->next->next=new Node(5);

    Node *mid=delMiddleNode(head);
    while(mid){
        cout<<mid->data<<" ";
        mid=mid->next;
    }
}