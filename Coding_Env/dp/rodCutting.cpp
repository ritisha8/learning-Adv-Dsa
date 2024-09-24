// this is unbounded knapsack which means we can take values more than once , and  how to recognise if a problem is unbounded knapsack or 0/1 knapsack
// you will know with examples where we can take as many instanace s of array elelmtns as wewant that is unbounded knasack, generally it is given in question or you will definately recognie by examples 
// here we are givena rod length ,like in knapsack 0-1,we were given capacity, and an array prices that tells the price as per rod length, and a length array willbe gIVEN , buit length array is not necesrray it mighht not be there , w ecan create vit on our own itsw just an index array that vstarts from 0 to length of price array
// here, we need to find the max profit ,of how to cut the rod in a way that we will get max profit.
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>prices,int length,int n){
    int t[n+1][length+1];
    vector<int>l(n);
    for(int i=0;i<n;i++)
    {
        l[i]=i+1;
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<length+1;j++){
            if(i==0 || j==0){
              t[i][j]= 0; // when length and price  array is emptry then we cant have any profit if we hae rod of any length. 
              // and if total length is 0 then array may be any big then profit will be 0 because we dont have any rod to cut 
        }
    }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<length+1;j++){
            if(l[i-1]<=j){  // if length array elemnts is less than total lentg of rod then we have two choices whether to take that much length with that prices or not , 
            // when we take here we will not do t[i-1], because when we take we can take the elemnt aggain in futurte so we will not eleiminate this elemnts complely , but whem we dont take this elemnt then we elimintate it completely , becaus ethink 
            // if you dont like ice cream and you are offered again and again , you wuill agagin and again say no only becaus eyou dont want it , but when you want it you will take it aggain and gagain also;
              t[i][j]=max(prices[i-1]+t[i][j-l[i-1]], t[i-1][j]) ;  // so when we take the elemnt we do t[i] , and when we dont take we do , t[i-1], becase then we have made a decsio  for ths elemnt that we are not going to take this , when are not going to take this we will not be needing it anytime further
            }
            else{
              t[i][j]= t[i-1][j];
            }
        }
    }
    return t[n][length];
}
int main(){
   int n;
   cin>>n;
   vector<int>prices(n);
   for(int i=0;i<n;i++){
    cin>>prices[i];
   }
   int length;
   cin>>length;
   cout<<solve(prices,length,n);
   return 0;
}