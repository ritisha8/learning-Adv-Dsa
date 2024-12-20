//what we are doing here is first finding the cost by subtracting the minimum 
//left ellemnt from the current ellemnt,then comparing it with profit if it maxmimum?
//,thebefore moving to the next elelmnt we are updating the minimum , 
//likeif the current elelmtn is lesser than the previous min ,thnewe update it to current elmnt, 
//sothat as we move to the next step we have our minimum ready  , we could have done it likeat 
//evry iterationwe traversedthe left ellmnt s and found themin and then subratected from the 
//ith ellemnt, but that would take n^2  complexity right?, we reduced it to n by calculatingmin at 
//every step before moving to the next iteration , so that next iterations min ellemtn is 
//ready to be subtarcted from

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