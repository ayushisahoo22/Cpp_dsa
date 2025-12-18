#include<bits/stdc++.h>
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

int main(){
    vector<int> arr={2,7,4,5};
    Node *y=new Node(arr[0]);
    cout<<y<<endl;  //address where y is residing
    cout<<y->data<<endl;  //data of y
    cout<<y->next<<endl;  //next ptr of y
}