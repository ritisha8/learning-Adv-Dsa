//here what we did first is we made a vis array of n+1 size because our input
//grpah was 1 based, so when graph is 1 based , we take vis[n+1], and then
//we initialize it wiht 0 and thenw e loopthrugh visited array. and run dfs 
//on each unvisited elemnt, and then indfs fucntion we make the node in input
// as visieted and then we visit its neighbours thrhough adj list, and then
//if they are not visited before we call dfs recursively on each one of them 
//until all nodesare viisted. in this way, all connected cities vill be visited
// in one go by dfs function and  will be marked as visited, and then when we go
// back after the recursion is fincished, we iterate in visited arry for nect
// ellemnt, and if they are visited , they will be skipped, if not, then weknow
// it was an unconnctd component , because if it was connected, it would
// have allready been visited by the dfs we did call before, so we make the
// counter plus, whenever we encouter a node which has not been visted before,
// to keep track of unconnected components or we can say different provincs

#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> adj[],int vis[]){
    vis[node]=1;
    for(auto it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            dfs(*it,adj,vis);
        }
    }
}
int NoOfProv(vector<int>adj[],int n){
    int vis[n+1]={0};
    int count=0;
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            count++;
            dfs(i,adj,vis);
        }
    }
    return count;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cout<<NoOfProv(adj,n);
}