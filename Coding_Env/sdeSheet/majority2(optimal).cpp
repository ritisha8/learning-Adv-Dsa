#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int>arr,int n){
    vector<int>ans;
    int el1=INT_MIN;
    int el2=INT_MIN;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(cnt1==0 && el2!=arr[i]){
            cnt1++;
            el1=arr[i];
        }
        else if(cnt2==0 && el1!=arr[i]){
            cnt2++;
            el2=arr[i];
        }
        else if(el1==arr[i]){
            cnt1++;
        }else if(el2==arr[i]){
            cnt2++;
        }else{
            cnt1--;cnt2--;
        }
    }
    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==arr[i]) cnt1++;
        if(el2==arr[i]) cnt2++;
    }
    if(cnt1 > n/3) ans.push_back(el1);
    if(cnt2 > n/3) ans.push_back(el2);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    vector<int>ans=solve(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}