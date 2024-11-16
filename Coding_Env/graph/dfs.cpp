#include<bits/stdc++.h>
using namespace std;
 void dfs(int node,vector<vector<int>>adj,int vis[],vector<int>&ls){
 vis[node]=1;
 ls.push_back(node);
 for(auto it=adj[node].begin();it!=adj[node].end();it++){
    if(!vis[*it]){
        dfs(*it,adj,vis,ls);
    }
 }
 }
vector<int> DFStraversal(vector<vector<int>>adj){
    int n=adj.size();
    int vis[n+1]={0};   // because starting node is 1
    int start=1;
    vector<int>ls;
    dfs(start,adj,vis,ls);
    return ls;

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int>v=DFStraversal(adj);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}