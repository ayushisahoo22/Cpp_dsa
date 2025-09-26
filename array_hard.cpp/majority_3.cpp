#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    /*vector<int> ans;
    map<int,int>mpp;
    int mini=(n/3)+1;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        //CHECKING BY MINI AND PUSHING IT IN ans..This reduces TC
        //if we iterate over every element to check if its occ is >n/3  [TC-->O(NlogN+N) for map]
        //But now it only take TC-->O(N)
        if(mpp[arr[i]]==mini){
            ans.push_back(arr[i]);
        }
        //AS THERE WILL BE TWO ELEMENTS IN ans ONLY
        if(ans.size()==2){
            break;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }*/


    //MOORE'S VOTING ALGO-II
    vector<int> ans;
    int cnt1=0,cnt2=0;
    int ele1=INT_MIN,ele2=INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1==0 && ele2!=arr[i]){
            ele1=arr[i];
            cnt1=1;
        }else if(cnt2==0 && ele1!=arr[i]){
            ele2=arr[i];
            cnt2=1;
        }else if(arr[i]==ele1){
            cnt1++;
        }else if(arr[i]==ele2){
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }
    //TO MANUALLY CHECK
    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(ele1==arr[i]){cnt1++;}
        if(ele2==arr[i]){cnt2++;}
    }
    int mini=(n/3)+1;
    if(cnt1>=mini){
        ans.push_back(ele1);
    }if(cnt2>=mini){
        ans.push_back(ele2);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}