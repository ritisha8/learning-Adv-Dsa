#include<bits/stdc++.h>
using namespace std;
// a better approach would be to take separate array for col numbers and row numbers
// and marking them as 1 whenever the elemnt in thta row of col is foudn zero , then 
//simply further by traversing again ,we can make all elelmnt s to eb zero whose eiher 
//col is 0 or row is zro , even if one of them is zero we mark itas zero , 
//but if none is zero we dont do anything to it
void solve(vector<vector<int>>&v,int n,int m){
    int row[n]={0};  // made a separte row array to mark rows, it is intialized to zero , 
    //so that when we mark it we know there isz ero foudn in this row or col
    int col[m]={0};   // a seoarate col array to mark cols
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){  //if any elemnt is found zero 
                row[i]=1;    // mark that row i = 1
                col[j]=1;    // mark that col j = 1
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]!=0){  // we check if the elemnt is alleready zero then we no need to make it zzero aggain
              if(row[i] || col[j]){  // herewe check for each ellemnt of array, if either of its row or col is marked we make it zero , other wise we move forward
                v[i][j]=0;
              }
            }
        }
    }
}

//now this better solutuon does take n*m time complexity , but space complexity is also n*m, we need to optimize the space complexity
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