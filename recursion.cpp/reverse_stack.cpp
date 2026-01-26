#include<bits/stdc++.h>
using namespace std;

//reverse the stack

void insertBottom(stack<int> &st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int t=st.top();
    st.pop();
    insertBottom(st,val);
    st.push(t);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int tp=st.top();
    st.pop();
    reverseStack(st);
    insertBottom(st,tp);
}

int main(){
    stack<int>st;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.push(x);
    }
    stack<int> temp = st;
    cout << "Before reverse: ";
    while(!temp.empty()){
    cout << temp.top() << " ";
    temp.pop();
    }
    cout << endl;
    reverseStack(st);
    cout << "After reverse: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}