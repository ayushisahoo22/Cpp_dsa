#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    string result="";
    vector<pair<int,string>>v={
        {1000,"M"},
        {900,"CM"},
        {500,"D"},
        {400,"CD"},
        {100,"C"},
        {90,"XC"},
        {50,"L"},
        {40,"XL"},
        {10,"X"},
        {9,"IX"},
        {5,"V"},
        {4,"IV"},
        {1,"I"}
    };
    for(auto it:v){
        while(num>0){
            if(it.first<=num){
                result+=it.second;
                num-=it.first;
            }else{
                break;
            }
        }
    }
    return result;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    string res=intToRoman(n);
    cout<<res;
}