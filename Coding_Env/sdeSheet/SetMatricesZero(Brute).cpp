//in this question we will be given a 2d matrix ,with zeros and other elemnets whichever cell contains 0,
//we have to mark whole of its row elemnts and its column elements to zero

// the brute force solutionthta comes to mind would be to traverse through all the llemnt of
// matirx and mark all rows and colums zero in which ellemnt 0is found , but that , would be wrong
// it will end up addiding extra zeroes than needed
// so when we find the elemnts with 0 we mark its row and column ellment as -1, leaving the llemtns allready zero
//so then again in end we traverse and  we will mark all -1 to 0, then we get our answer
#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>&v,int n ,int m){
   for (int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]==0){
            for(int p=0;p<n;p++){
                if(v[p][j]!=0){
                    v[p][j]=-1;   // for col j we mark all the row elemtns except zero to -1
                }
            }
            for(int q=0;q<m;q++){
                if(v[i][q]!=0){
                    v[i][q]=-1;  // for row i we mark all the col elemnts except zero to -1
                }
            }
        }
    }
   }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]==-1){
            v[i][j]=0;  // then we make it zero all the ellemnts that are -1
        }
    }
   }
}

//this apprroach is taking n^3 complexity because we are trvaersing through 2d matrrix so n^2 ,
// then we are making row an columns 0 inside with another loop going from 0 to n 
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