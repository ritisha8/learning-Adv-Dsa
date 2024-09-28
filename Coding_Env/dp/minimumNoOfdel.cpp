#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());
    int n=s.length();
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
            if(s[i-1]==s2[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return n-t[n][m];
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}