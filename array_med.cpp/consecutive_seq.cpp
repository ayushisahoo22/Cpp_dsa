#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the vector ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //distorting the array
    sort(arr.begin(),arr.end());
    int count=0,longest=1;
    int last_small=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]-1==last_small){
            count+=1;
            last_small=arr[i];
        }else if(arr[i]!=last_small){
            count=1;
            last_small=arr[i];
        }
        longest=max(longest,count);
    }
    cout<<longest;
}