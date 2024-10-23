#include<bits/stdc++.h>
using namespace std;
int t[102][1002];
int solve(vector<int>v,int n,int k){
    if(n==0){
        t[n][k]= 0;  // we are not directly returning it because then in between rec calls if we get n=0  k=0 then it will directly come here and return 0 
        //, what we want is the sum of including including and not including the element in a subset, and we will just get 0 on the basis of one condition directly which is wrong
    }
    if(k==0){
        t[n][k]= 1; 
    }
    if(t[n][k]!=-1){
        return t[n][k];
    }
    if(v[n-1]<=k){
        return t[n][k]=solve(v,n-1,k-v[n-1]) + solve(v,n-1,k);
    }
    else{
        return  t[n][k]=solve(v,n-1,k);
    }
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    memset(t,-1,sizeof(t));
    cout<<solve(v,n,k);
    return 0;
}