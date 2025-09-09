#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int right=0;int left=n-1;
    int mid=(left+right)/2;
    vector<int> nums(n);
    //for even
    if(n%2==0){
        for(int i=1;i<=n/2;i++){
            nums[right]=i;
            right++;
            nums[left]=-i;
            left--;
        }
    }else{          //for odd add 0 in middle
        for(int i=1;i<=n/2;i++){
            nums[right]=i;
            right++;
            //nums[mid]=0       because it will set mid=0 again and again
            nums[left]=-i;
            left--;
        }
        nums[mid]=0;      
    }

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}