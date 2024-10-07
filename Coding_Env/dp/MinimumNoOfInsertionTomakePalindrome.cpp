#include<bits/stdc++.h>
using namespace std;
int solve(string S){
    int n=S.length();
    string M=S;
    reverse(M.begin(),M.end());
    int m=n;
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S[i-1]==M[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    if(t[n][m]==0) // if there is nothing common betwen the string and its reverse then wewill simpley return 1 lessthan string size because in order to make it  aplaindrome we require exactly the same letters that are in string atleats one more time but the middle ellemnt can be adjusted with one only
    {
        return n-1;   
    }else{
        return n-t[n][m];
    }
}
int main(){
    string S;
    cin>>S;
    cout<<solve(S);
    return 0;
}