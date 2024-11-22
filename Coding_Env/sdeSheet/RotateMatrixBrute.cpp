#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<vector<int>>&v,int n,int m){
    vector<vector<int>>mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[j][n-1-i]=v[i][j];
        }
    }
    return mat;
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
    vector<vector<int>>mat=solve(v,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}