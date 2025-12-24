#include<bits/stdc++.h>
using namespace std;

//find middle of linked list
//by tortoise hare algo
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

Node *middleNode(Node *head){
    Node *tortoise=head;
    Node* hare=head;
    while(hare!=NULL && hare->next!=NULL){
        //moves one step
        tortoise=tortoise->next;

        //moves two step
        hare=hare->next->next;
    }
    return tortoise;
}

int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next= new Node(3);
    head->next->next->next= new Node(4);
    head->next->next->next->next=new Node(5);

    Node *mid=middleNode(head);
    while(mid){
        cout<<mid->data<<" ";
        mid=mid->next;
    }
}