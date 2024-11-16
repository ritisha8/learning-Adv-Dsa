//herewhat we do is first we make the starting node as viosited and
// then we push it intoans vector, thenwe iterate thrpugh each of its
// neigbours and then we recursively call df for its neighbour, and
// then we make the neigbour visted and then we push it into ans vector, 
//and then we explore tehneighborus neioghbour , and then we recurisvely call
// dfs on its neighbours whoare not allready visietd, then when all the 
//nodes are visietd , we bactrak and then wesee if there aare any other
// neighbours not visted of that call, if no we backtrack again until we raech 
//a point when all recursive callsare bactracked and all nodes are visisted 
//at each call 

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