#include <bits/stdc++.h> 
using namespace std;

//swap even bits of n with odd bits
//consider lsb to odd bit

int swapAdjacentBits(int n)
{ 
    int odd=n& 0x55555555;  //odd masking-10101 
    int even= n& 0xAAAAAAAA;  //even masking-01010
    odd<<=1;
    even>>=1;
    return odd | even;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans= swapAdjacentBits(n);
    cout<<ans;
}