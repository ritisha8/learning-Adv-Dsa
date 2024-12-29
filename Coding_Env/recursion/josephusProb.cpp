#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&v,int index,int k){
    if(v.size()==1){   // least valid input
     return v[0];
    }
    //hypothesis design that this function will return the output of one person left at the end
    // so the smaller input function will also return the same last person left at end
    // we cant just make input small by taking out the last index , here their is acriteria in which the person at kth positiion dies everytime
    // so we will reduce inout in that way
    index=(index + k )% v.size();  // this return new or kth index from which the new counting will start aswehave allreadyreduced k from main
    v.erase(v.begin()+index);  //erased the element
    return solve(v,index,k);   // recurisve call to again count till k and erase the erson at the kth 
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;   // the count at which we need to kill the person
    k--;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int index=0;         // the startign person fromwhich the count will start till k
    
    cout<<solve(v,index,k);
    return 0;

}