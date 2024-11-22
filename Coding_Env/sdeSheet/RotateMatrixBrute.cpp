#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<vector<int>>&v,int n,int m){
    vector<vector<int>>mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[j][n-1-i]=v[i][j];      //col of org is chnaged to row of new
        }                              // row of org is changed to n-1-i col of new
        // why n-1 -i because row is changed to last column-row no. ,like first row has become last column,
        // second row has become second last column
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