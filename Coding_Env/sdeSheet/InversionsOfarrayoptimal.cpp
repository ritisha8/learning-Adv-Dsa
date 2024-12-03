#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void Merge(vector<int> &arr,int low,int mid, int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            //whenevr left part is found greater than right part , we increaseour counter value,
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void MergeSort(vector<int>&arr,int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}
int solve(vector<int>&arr,int n){
    MergeSort(arr,0,n-1);  //using mergeSort
    return cnt;
}
int main(){
     int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n);
    return 0;
}