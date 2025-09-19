#include <bits/stdc++.h>
using namespace std;

// Last element will always be the leader
// The element will be leader when every right elements to it are smaller
int main()
{
    int n;
    cout << "Enter the size of the vector ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans;

    // TC--->O(N^2)
    /*for(int i=0;i<n;i++){
        bool isLead=true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                isLead=false;
                break;
            }
        }
        if(isLead){
            ans.push_back(arr[i]);
        }
    }*/

    // TC--->O(N)
    int max = arr[n - 1];
    ans.push_back(max);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}