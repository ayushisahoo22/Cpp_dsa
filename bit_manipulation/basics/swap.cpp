#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    a=a^b;
    b=a^b;   //(a^b)^b = a
    a=a^b;   //(a^b)^a = b
    cout<<"After swapping: ";
    cout<<a<<" "<<b;
}
