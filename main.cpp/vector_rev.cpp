// inserting elements of digit in an array using VECTOR,REVERSE
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int maximum69Number (int num){
    vector<int> digits;
    while(num>0){
        digits.push_back(num%10);
        num = num/10;
    }
    reverse(digits.begin(),digits.end());
    for(int i=0;i<digits.size();i++){
        printf("%d  ",digits[i]);
    }
}
int main(){
    int n = 98754;
    maximum69Number(n);
    return 0;
}