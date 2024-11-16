//this is adjecency list representation

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;  // n for no of vertices and m for no. of edges
    cin>>n>>m;  // we take ip for howmuch no. of edges and vertices the graph is
    vector<int> adj[n+1];  // this is a array of vectors adj list , which stores empty vector at each index , and as we have vertices from 1 to n , we take n+1 size
    for(int i=0;i<m;i++){   // we will loop through each edge to input the vertices that are connected to form and edge
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);  //then we add it to u vector , which stores all its neighbours 
        adj[v].push_back(u);  //then we add it to v vector, whcih stores al it neighbours
    }
    // this will ensure that we have printed correct neighbours of each vertex ,
    //it is a way to check the representation
    for(int i = 1; i <= n; i++){
    cout << i << " -> ";
    for(int j = 0; j < adj[i].size(); j++){
        cout << adj[i][j] << " ";
    }
    cout << endl;
}


    return 0;
}