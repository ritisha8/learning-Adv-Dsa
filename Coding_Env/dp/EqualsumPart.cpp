#include<bits/stdc++.h>
using namespace std;
int t[1000][1000];
bool SubsetPossible(vector<int>arr,int sum,int n){
if(n==0){  // when elemnas are not there how ill sum be found  except just one case when sum=0, then empty subet can be found
    return false;
}
if(sum==0){
    return true;  //when sum is zero empty subet can eb found evrywhere
}
if(t[n][sum]!=-1){
    return t[n][sum];
}
if(arr[n-1]<=sum){
  return t[n][sum]=arr[n-1]+SubsetPossible(arr,sum-arr[n-1],n-1) || SubsetPossible(arr,sum,n-1);
}


else{
  return SubsetPossible(arr,sum,n-1);
}
    
}
bool EqualSum(vector<int> arr,int sum,int n){
  if(sum%2==0){
    sum=sum/2;
    return SubsetPossible(arr,sum,n);
  }
  else{
    return false;
  }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    memset(t,-1,sizeof(t));
    cout<<EqualSum(arr,sum,n);
    return 0;
}