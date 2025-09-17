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
    //distorting the array  ---> O(NlogN)
    /*sort(arr.begin(),arr.end());
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
    cout<<longest;*/

    //by not sorting   TC---> O(3N)
    //                 SC---> O(N) 
    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1) != st.end()){
                cnt+=1;
                x+=1;
            }
            longest=max(longest,cnt);
        }
    }
    cout<<longest;
}