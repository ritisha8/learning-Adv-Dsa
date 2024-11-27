// brute force
//TC: O(nlogn) + O(n); where n is the size of array
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr){
    // step1 : sort the array
    int num=0;
    sort(arr.begin(),arr.end());
    //step2 ; trversing linearly to check if at any point arr[i]==arr[i+1] that is its next element
    for(int i=0;i<arr.size();i++){
        if(arr[i]==arr[i+1]){
         num=arr[i];
         break;
        }
    }
    return num;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr);
    return 0;
}