#include<bits/stdc++.h>
using namespace std;
void solve(int k , vector<int>&v, vector<int>&res){
    if(k==0){
        int ans=0;
        for(int i=0;i<v.size();i++){
         ans=ans*10+v[i];
        }
        res.push_back(ans);
    }
    // if k is not 1 and hence it has two places ,then0 cant be at first place because thta woukd makeit a single digit elemnt
    for(int i=1;i<=9;i++){
        if(v.size()==0 || v[i]>v[v.size()-1]){
            v.push_back(i);
            solve(k-1,v,res);
            v.pop_back();
        }
    }
}
vector<int> Nnumber(int k){
    vector<int>res;
    vector<int>v;
    if(k==1){
        for(int i=0;i<=9;i++){
            res.push_back(i);
        }
    }else{
         solve(k,v,res);
    }
    return res;
}
int main(){
    int k;
    cin>>k;
    vector<int>v=Nnumber(k);
    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }
    return 0;
}