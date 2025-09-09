#include<bits/stdc++.h> //to include all the module
// #include <iostream>
// #include <climits> // for INT_MIN & INT_MAX
using namespace std;
int main()
{
    int arr[100];
    int n;
    cout << "Enter the size of array ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //using sort
    // sort(arr,arr+n);
    // int small=arr[1];
    // int large=arr[n-2];
    // cout<<"Smallest element: "<<small<<endl;
    // cout<<"largest element: "<<large<<endl;

    //without using sort
    int smallest = INT_MAX, second_smallest = INT_MAX;
    int largest = INT_MIN, second_largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // for smallest and second smallest
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < second_smallest)
        {
            second_smallest = arr[i];
        }
        // for largest and second largest
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] != largest && arr[i] > second_largest)
        {
            second_largest = arr[i];
        }
    }
    cout <<"Second largest element is: "<< second_largest << endl;
    cout<<"Second smallest element is: " << second_smallest;
}