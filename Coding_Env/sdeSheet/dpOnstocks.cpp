#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>v,int n){  
    int profit=0; // for the fiirst elemnt profit will be zero as there isno left minimum 
    int mini=v[0]; // and min will be first elemnt only
    for(int i=1;i<n;i++){
      int scost=v[i]-mini;     // the point where we sold , so the profit will be= this point - min from 0 to i-1,
      profit=max(scost,profit);   // then calcuating the max profit
      mini=min(mini,v[i]);  // then updating mini with currect elelmnt is the elmnt is found lessthan prev minimum
      //  , updating mini is dp , when we rember the past, here are taking the past with us at each step
    }
    return profit;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<solve(v,n);
    return 0;
}