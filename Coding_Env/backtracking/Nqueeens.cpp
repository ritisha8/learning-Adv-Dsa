#include<bits/stdc++.h>
using namespace std;
bool check(int colidx,int rowidx,int n, vector<vector<int>>board){
    //for left side
    for(int col=0;col<colidx;col++){
       if(board[rowidx][col]==1){
        return false;
       }
    }
    //for diag1
    int i=rowidx,j=colidx;
    while(i>=0 && j>=0){
       
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    // for diag2
     i=rowidx, j=colidx;
    while(i<n && j>=0){
       
        if(board[i][j]==1){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(int colidx,vector<int>&temp,vector<vector<int>>&ans,int n,vector<vector<int>>board){
    //base case
    if(colidx==n){
        ans.push_back(temp);
        return;
    }
    for(int rowidx=0;rowidx<n;rowidx++){
        if(check(colidx,rowidx,n,board)){
            board[rowidx][colidx]=1;
            temp.push_back(rowidx+1);  // beacuse we have to return 1 based index ans
            solve(colidx+1,temp,ans,n,board);
            board[rowidx][colidx]=0;
            temp.pop_back();
        }
    }
}
vector<vector<int>> Nqueens(int n){
    vector<vector<int>>ans;
    vector<int>temp;
    vector<vector<int>>board(n, vector<int>(n,0));
    solve(0,temp,ans,n,board);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>v=Nqueens(n);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}