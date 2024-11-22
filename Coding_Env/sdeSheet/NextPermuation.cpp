#include<bits/stdc++.h>
using namespace std;
vector<int> NextPermuation(vector<int>v,int n){
    //dipping point
    int index=-1;
    for(int i=n-2;i>=0;i++){
        if(v[i]<v[i+1]){
            index=i
            break;
        }
    }
    //if no dipping point is found that is no eelmtn is smaller than its enxt index
    if(index==-1){
        reverse(v.begin(),v.end());   // then  that mean the arrangement is in sorted increasing order formback , so we reverrse it and return it, that would be the next permuation
        return v;
    }
    //if dipping point is found, we are assumming before dipping point evry elemnt is in increasing order because dipping point is the one where an ellemnt smaller than its prev 
    for()
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    NextPermuation(v,n);
    return 0;
}