#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool isPower=true;
    while(n>1){
        int rem=n%2;
        if(rem!=0){
            isPower=false;
            break;
        }
        n=n/2;
    }
    if(isPower){
        cout<<"Power of 2";
    }else{
        cout<<"Not a power of 2";
    }
    
}