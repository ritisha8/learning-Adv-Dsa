#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<vector<int>>&v){
    // sort the array
    sort(v.begin(),v.end());
    int n=v.size();
    vector<vector<int>> ans;
    //now travesing 
    for(int i=0;i<n;i++){
        int start=v[i][0];
        int end=v[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(v[j][0]<=end){
                end=max(v[j][1],end);
            }else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>ans=solve(v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}