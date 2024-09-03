// variation of 0-1 knapsack , 0-1 means whther we take the elemnt as whole or we dont take it at all
#include<bits/stdc++.h>
using namespace std;
int t[100][100];

bool subsetSum(vector<int>v,int sum,int n){
    // first write a recrusive function 
    // here we decide for the last elemnt of v whether totake it or not , in order to get the sum
    // same like last time if ellemnet is greater than sum we dont consider it and if it is smaller, we have two decison of taking and not taking which wil be represnted through decsion tree
    
    if(n==0){
        // least valid input  ,if vector size is 0 , then sum may be anything , then only if sum is 0 then subsetsum will be true otherwise when sumhas vaues more than 0 then sum will never be found in vector subsets because vector is mepty right?
        return false; // if vector size is 0 and sum is zero sill we can take an dempty subset whose sum is 0  // so we rturn true
    }
    if(sum==0){
        return true; // if sum is 0 then in every case subset can be founf that is empty set, it is subset and also its sumis 0 , so it will always eb true 
    }
    if(t[n][sum]!=-1){
        return t[n][sum];
    }
    
    if(v[n-1]<=sum)
    {
        return t[n][sum]=subsetSum(v,sum-v[n-1],n-1) || subsetSum(v,sum,n-1);
    }
    if(v[n-1]>sum){
        return t[n][sum]=subsetSum(v,sum,n-1);
    }
}
int main(){
    memset(t,-1,sizeof(t));
    int sum;
    cin>>sum;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    cout<<subsetSum(v,sum,n);
    return 0;


}