#include<bits/stdc++.h>
using namespace std;
 int main(){
    //add only 1 & 0 to the arr
    int arr[100];
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //not using temp vector
    int count=0,maxCount=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxCount=max(maxCount,count);
        }else if(arr[i]==0){
            count=0;
        }
    }
    cout<<"Maximum consecutive 1 are: "<<maxCount;

    //using temp vector
    /*int count=0;
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
        }else if(arr[i]==0){
            temp.push_back(count);
            count=0;
            // break;
        }
    }
    temp.push_back(count);      //to count for the 1s at the end after 0
    //to find max from temp
    int max=temp[0];
    for(int i=0;i<temp.size();i++){
        if(temp[i]>max){
            max=temp[i];
        }
    }*/
    //cout<<"Maximum consecutive 1 are: "<<max;
 }