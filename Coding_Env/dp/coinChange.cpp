// here we are given coin denominzations and we need to find out the max number of subsets we can make for a sum given in the question
// and we can use the coin denominations again as again 
#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>coins,int amount,int n){
    int t[n+1][amount+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<amount+1;i++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<amount+1;i++){
            if(coins[i-1]<=j){
                t[i][j]=t[i][j-coins[i-1]] + t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][amount];
}
int main(){
   int n;
   cin>>n;
   vector<int>coins(n);
   for(int i=0;i<n;i++){
    cin>>coins[i];
   }
   int amount;
   cin>>amount;
   cout<<solve(coins,amount,n);
   return 0;
}