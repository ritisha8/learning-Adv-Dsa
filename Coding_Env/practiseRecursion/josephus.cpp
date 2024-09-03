#include<bits/stdc++.h>
using namespace std;
int solve(int k,vector<int>v,int index){
    if(v.size()==1){
        return v[0];
    }
    index=(index+k)%v.size();
    v.erase(v.begin()+index);
    return solve(k,v,index);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k;
    cin>>k;
    k--;
    cout<<solve(k,v,0);

    return 0;
}