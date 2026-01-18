#include<bits/stdc++.h>
using namespace std;

// given a string s, sort it in decreasing order based on the frequency of the characters. 
// The frequency of a character is the number of times it appears in the string.

string frequencySort(string s) {
    pair<int,char> freq[256];
    for(int i=0;i<256;i++){
        freq[i]={0,char(i)};
    }
    for(char c:s){
        freq[(unsigned char)c].first++;
    }
    sort(freq,freq+256,[](auto &a,auto &b){
        return a.first>b.first;
    });
    string res="";
    for(int i=0;i<256;i++){
        while(freq[i].first>0){
            res.push_back(freq[i].second);
            (freq[i].first)--;
        }
    }
    return res;
}

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    string ans=frequencySort(s);
    cout<<ans;
}