#include<bits/stdc++.h>
using namespace std;
bool solve(String S, string M){
    int n=S.length();
    int m=M.length();
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(S[i-1]==M[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }else{
                t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
    }
    if(t[n][m]==n){  // if longest common subsequence is equal to s length then definately s exists in M ,
    //we know lcs gives the longest common subsequence in 2 strings ,so if the logest common subsequence becomes 
    //equal to first string length then it exits in second string 
        return true;  
    }else{    
        return false;
    }
}
int main(){
     string S;
     cin>>S;
     string M;
     cin>>M;
     cout<<solve(S,M);
     return 0;
}