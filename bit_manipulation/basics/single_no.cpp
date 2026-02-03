#include<bits/stdc++.h>
using namespace std;

//return the single no

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int num=0;
    for(int i=0;i<n;i++){
        num^=arr[i];
    }
    cout<<num;
}