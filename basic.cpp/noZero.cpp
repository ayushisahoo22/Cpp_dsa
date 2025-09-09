//Sum of two no-zero numbers which give n
//No zero numbers are not 10,1002...The number should not contain 0 at all
#include <bits/stdc++.h>
using namespace std;
bool isValid(int n){
    string s=to_string(n);
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    for(int a=1;a<n;a++){
        int b=n-a;
        if(isValid(a) && isValid(b)){
            cout<<a<<" "<<b;
            return 0;
        }
    }
    cout<<"No such pair found";
    return 0;
    
}