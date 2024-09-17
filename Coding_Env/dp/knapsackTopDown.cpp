// this top down aproach involves converting the recursive solution into iterative one
//or we can start by drawing the matrix as well
#include<bits/stdc++.h>
using namespace std;
int t[1000][1000];
int knapsack(vector<int>wt,vector<int> val,int W,int n){
//converting the base case
for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
        if(i==0|| j==0){
            t[i][j]=0;
        }   // that means when items are not there .ie.0, then even if we have capacity ,max profit will be zero 
        //orwhen cap is 0 , even whenitems will be there stiill we cant put in knapsack any, so then also profit is zero
    }
}

for(int i=1;i<n+1;i++){
    for(int j=1;j<W+1;j++){
        if(t[i-1][j]!=-1){
            t[i][j];
        }
        if(wt[i-1]<=j){
           t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
        }
        else{ 
           t[i][j]=t[i-1][j];
        }
    }
}
return t[n][W];
}
int main(){
    int W;  // capacity
    cin>>W;
    vector<int> wt={4,5,1};  //wt of items
    vector<int> val={1,2,3};  // val of items
    int n=wt.size();  // items
    memset(t,-1,sizeof(t)); //setiing all values in t matrix as -1;  we will see why further
    cout<<knapsack(wt,val,W,n);
    return 0;
    
}