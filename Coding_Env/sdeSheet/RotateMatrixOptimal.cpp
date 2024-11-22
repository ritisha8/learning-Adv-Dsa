//optimal solution would be to transposethe matrix and then reverse each of its rows
//trnaspose means row is changed to col , like first row becomes the first column, econd row becomesthe second column 
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>&v, int n , int m){
    for(int i=0;i<n-1;i++){         // row will be tarversed till last second, but col will be tarversed till after the ith elementt, to avoid editing diagnal, as that remain same in transpose
        for(int j=i+1;j<n;j++){
           swap(v[i][j],v[j][i]);  
        }
    }
    for(int i=0;i<n;i++){
        reverse(v[i].begin(),v[i].end()); //then reverse each row
    }
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
    solve(v,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}