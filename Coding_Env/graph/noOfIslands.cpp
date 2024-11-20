#include<bits/stdc++.h>
using namespace std;
void bfs(int row, int col, vector<vector<int>>&vis,vector<vector<int>>grid,int n, int m){
    // vis array is passed by reference because we have made avoid function and it wicreate new copy of vis array andmakthe visited in it and hence when the call finishes and we come back here,
    // the visted array in this function remains non visted only so we were getting the wrong ans
    vis[row][col]=1;    //first step we do inbfsis mark thenode as vsited and  push it into queue
    queue<pair<int,int>>q;
    q.push({row,col});// then we push the starting node in queue
    //thewe check its neighbours right? but before that we store it into a variable and then pop the queue

    while(!q.empty()){  //thenwe run a whileloop until queue is empty
      int row=q.front().first; // stored in variable 
      int col=q.front().second;
      q.pop();  // and hen popped

     // thenwe iterated through all its neighbours in adjacency matrix , but here we dont have adjacency matrx ,
     // here we have the grid , and we know all its neighbours in eight drection are going to be ,
     // (row-1, col),(row-1,col+1),(row-1,col-1),(row,col+1),(row,col-1),(row+1,col+1),(row+1,col),(row+1,col-1)
    for(int drow=-1;drow<=1;drow++){
        for(int dcol=-1;dcol<=1;dcol++){   // this will ensure it will go to (row-1,col-1), (row-1,col),(row-1,col+1), and etc 
          int nrow=row+drow;   // neighbour row will be nrow= row+drow value example ifrow is 1 delrow -1, then nrow=0
          int ncol=col+dcol;   //neighbour col will be col +dcol examle is col was 2 , amd dcol was -1, then ncol=1 
          // both col and row will be depreciated by one in first iteration hecne pointing to their left diagnol neighbour, 
          //in this way it will check for all its neigbours
          if(nrow>=0 && nrow<n && ncol<m && ncol>=0 &&    // then we chck if the nrow and col value is valid, it could be -1 as well 
           grid[nrow][ncol]==1 && vis[nrow][ncol]==0){   //whcih is invalid, sowe check for its value, if the value of both row and collies between 0 
          //and nthen we checkif theyare land or 1, and then we check if they are visted or not thn i allthe 
          //conditions are met we make the neighbur row as vsited and then w push it into queue
            vis[nrow][ncol]=1;
            q.push({nrow,ncol});
           }
        }
        // then the whole process continues until q is empty and wethen pop out the next front ellemntof queue , 
        //and first store the row and col value in variables,thenwe check for its neighbours if they are valid
        // and then if they are land if they are vsiisted, if not we vsit them and mark them as 1in svisted array 
        //and then we push them into queue , then again the whole procces continue until the queue is empty
    }
}
}
int NoOfIslands(vector<vector<int>>grid,int n,int m){
    vector<vector<int>>vis(n,vector<int>(m,0));  // why do we make a2d visited array here, 
    //because we have thenodes in the form fof 2d matrix so we will store themas 
    //pair in queue, and if we are storing themas pair , we needa vsiisted 2d array
    // as wel whcih is the copy of grid but zero, so that we willtarverse through 
    //the 2d vis aray to check which are land or 1s and if they ae land they shuld 
    //be non visited, and then run bfs on them , bfs will ensure that allthe nearest
    // ones are marked as visited ,and hence , when we come back to chck for tarversal
    // in vis array it willnot take into account the connected conomponents or the 1s alltogether,
    // it will take a new starting index inthe form of row and column which has not been
    // encountered yet
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0){  
                count++;  // each time the we encounter a non visted land or 1 we incement 
                //our counter, because if we encounter a 1 whch its bfs will mark all the
                // nearest ones as visted and hence we will only encounter another land 
                //if it not in any way nearest neighbour of those we allready visited,
                // because if it were i would have been tarversed as well and made into visited
              bfs(i,j,vis,grid,m,n); // what we did in bfs first we make the 
              //node as viisted and then we push it into queue, here we
              // have starting node inthe form of row col so we take visited array as 2d array
            }
        }
    }
    return count;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<NoOfIslands(grid,n,m);
    return 0;
}