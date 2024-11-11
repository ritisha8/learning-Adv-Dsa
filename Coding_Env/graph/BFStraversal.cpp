#include<bits/stdc++.h>
using namespace std;
vector<int> BFStraversal(vector<vector<int>> &adj){
    int n=adj.size();  // as this adj list stores all the vertices neighbours , so the no. of nodes we get from here as size of adj list
    //we make a queueu to store all the neighbouring nodes
    queue<int>q;
    //then we make a visited array , whichw ill store the nodes whicha are visited or not, id the nodes indexing start from 0 wetake vis array of n , bu tif it starts from 1 we take the visisted array of n+1 size
    int vis[n]={0};
    //now we push the 0th node into the queue, node numbers will always start from either zero or 1, so we will always push the first node into queue
    vis[0]=1;  // first we mark it as 1 to mark that it is visited 
    // then we push the node into the queue
    //we cant push the node which has allaredy been visited into teh queue
    q.push(0);
    //answer vector
    vector<int>ans;
    while(!q.empty()){   // now we run a loop until queue is empty 
       int node = q.front();   // first we will pop the first node by storing its vakue in a vriable and then popping it and then pushing it into answer vector
       q.pop();
       ans.push_back(node);

       //now we run a for loop to check its neghboring elelmnts in adj list
       for(auto it=adj[node].begin();it!=adj[node].end();it++){
        //now we check first if the neighbour is visited or not 
        if(vis[*it]!=1){
            vis[*it]=1;  //first mark it visted 
            q.push(*it);   //then push it into queue
        }
       }
      //then we go again after all the neighbours are pushed into queue the while loop runs agagin and stores thefront lelmnt in node
      //and then pops it ,and then the element stored will pushed into answer vector and then we check for the neighbiring nodes of the stored q.front elemtn that we popped, 
      //now we loop through adj list , for all the neighboring ellemnts 
      //and then we check if visited if the neighboru ahas allready been visited, if yes , we dont vsit it again and move foward to henext neighbour,adn push it into queue, 
      //queue will never hve elemnts whcha are allready visited once
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
      int u,v
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    BFStraversal(adj);
    return 0;
}