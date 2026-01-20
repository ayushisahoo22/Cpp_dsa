#include<bits/stdc++.h>
using namespace std;

// Given an array ‘arr of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
// There are a ‘m’ number of students, and the task is to allocate all the books to the students.

// Allocate books in such a way that:
// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.

// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

int countStudents(vector<int>arr,int p){
    int n=arr.size();
    int student=1;
    int pages=arr[0];
    for(int i=1;i<n;i++){
        if((pages+arr[i])<=p){
            pages+=arr[i];
        }else{
            student++;
            pages=arr[i];
        }
    }
    return student;
}

int bookAllocation(vector<int>arr,int m){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(countStudents(arr,mid)==m){
            ans=mid;
            high=mid-1;
        }else if(countStudents(arr,mid)<m){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=bookAllocation(arr,m);
    cout<<ans;
}