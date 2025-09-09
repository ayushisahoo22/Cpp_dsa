#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int n;cout<<"Enter the size of array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int k=st.size();
    int j=0;
    for(auto it:st){
        arr[j++]=it;
    }
    cout<<"After removing duplicates"<<endl;
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
}