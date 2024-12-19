#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr,int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;   // because 0-low-1 are 0s
            mid++;   // and low to mid are 1s
        }
        // here we picked up a 1 from low and swapped it with 0 andnow we have 1 at mid and 0 at low,sowe do low++ to keep thelow at correct place, and mid++ to keep the 1at ocrrect place
        else if(arr[mid]==1){
            mid++;  // because low to mid-1 are 1s only 
        }
        else{
           swap(arr[mid],arr[high]);
           high--;  // high ka unsorted element uthakr mid me daldiya or midka 2 uthakr high me rkhdiya, because high+1 to n-1 are 2s
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    solve(arr,n);
    for(int i=0;i<n;i++){
    cout<<arr[i];
    }
    return 0;
}