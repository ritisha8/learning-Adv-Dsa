// TC: O(nlogn) + O(mlogm) +O(min(n+m))
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr1,vector<int>&arr2,int n,int m){
    int i=n-1;
    int j=0;
    while(i>=0 && j<m){
        if(arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        }
        if(arr1[i]<arr2[j]){
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

}
int main(){
    int n,m;
cin>>n>>m;
vector<int>arr1(n);
for(int i=0;i<n;i++){
  cin>>arr1[i];
}
vector<int>arr2(m);
for(int i=0;i<m;i++){
    cin>>arr2[i];
}

solve(arr1,arr2,n,m);

for(int i=0;i<n;i++){
  cout<<arr1[i]<<" ";
}
cout<<endl;
for(int i=0;i<m;i++){
    cout<<arr2[i]<<" ";
}
return 0;
}
