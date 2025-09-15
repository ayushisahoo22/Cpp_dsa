#include<bits/stdc++.h>
using namespace std;

void printF(int ind ,vector<int> &ds, int arr[],int n){
    if(ind>=n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    //take particular index into the subsequence
    ds.push_back(arr[ind]);
    printF(ind+1,ds,arr,n);
    //not take condition , this element is not added to the subsequence
    ds.pop_back();
    printF(ind+1,ds,arr,n);
}
int main(){
    int arr[]={3,1,2};
    int n=3;   //no of elements in array
    vector<int> ds;
    printF(0,ds,arr,n);
    return 0;
}

//TC---> O(N*2^N) 
    //for every idx we have 2 opt(2^N) and then for every subsequence we have to iterate for loop(N*2^N)

//SC---> O(N)
