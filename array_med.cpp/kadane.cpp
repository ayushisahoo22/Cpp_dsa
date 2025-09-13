#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int start;
    int indStart=-1,indEnd=-1;
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
            indStart=start;
            indEnd=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout<<maxi<<endl;
    for(int i=indStart;i<=indEnd;i++){
        cout<<arr[i]<<" ";
    }
}