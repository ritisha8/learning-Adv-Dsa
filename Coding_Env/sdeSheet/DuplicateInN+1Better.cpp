//better solution
// tc: O(n) 
// sc: O(n)
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr){
    int num=0;
    int n=arr.size();
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        if(hash[arr[i]]==1){
            num=arr[i];
            break;
        }
        hash[arr[i]]++;
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