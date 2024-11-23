#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<vector<int>>&v){
    vector<vector<int>> ans;
    int n=v.size();
    for(int i=0;i<n;i++){
        if(ans.empty() || v[i][0]>ans.back()[1]){   // when a new interval is created ? when ans is empty and when the intervals[i][0] is greater than whatever is stored in ans.back()[1]
            ans.push_back(v[i]);
        }
        else if(v[i][0]<=ans.back()[1]){
            ans.back()[1]=max(ans.back()[1],v[i][1]);
        }
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