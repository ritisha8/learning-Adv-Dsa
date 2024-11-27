//  brute force
// TC : O(n+m)
// SC : O(n+m)
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&arr1,vector<int>&arr2,int n,int m){
int i=0;
int j=0;
int k=0;
vector<int>arr3(n+m);
while(i<n && j<m){
    if(arr1[i]<=arr2[j]){
     arr3[k]=arr1[i];
     k++;
     i++;
    }else{
        arr3[k]=arr2[j];
        k++;
        j++;
    }
}
while(i<n){
    arr3[k]=arr1[i];
    k++;
    i++;
}
while(j<m){
    arr3[k]=arr2[j];
    k++;
    j++;
}
for(int i=0;i<n+m;i++){
    if(i<n){
        arr1[i]=arr3[i];
    }
    else{
        arr2[i-n]=arr3[i];
    }
    
}
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