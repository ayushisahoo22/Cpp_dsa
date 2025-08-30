#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size,q;
    cin>> size>>q;
    vector<int> n(size);
    
    for(int i=0;i<size;i++){
        int k;
        cin>>k;
        vector<int> arr(k); 
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        cin>>n[i];
    }
    return 0;
}