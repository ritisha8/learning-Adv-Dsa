#include<bits/stdc++.h>
using namespace std;
int solve(string s, string d){
    int n=s.length();
    int m=d.length();
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for (int j=0;j<m+1;j++){
            if(i==0 ||j==0){
                t[i][j]= 0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for (int j=1;j<m+1;j++){
            if(s[i-1]==d[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }
            else{
                t[i][j]=0;  //in lcs we put max of i-1 and j-1 , this is the ariation in this question
            } 
        }
    }
    // here we willnot return t[n][m]
    // here we will return max of among t[n+1][m+1] matrix
    int mx=INT_MIN;
    for(int i=0;i<n+1;i++){
        for (int j=0;j<m+1;j++){
            mx=max(mx,t[i][j]);
        }
    }
    return mx;
}
int main(){
    string s;
    cin>>s;
    string d;
    cin>>d;
    cout<<solve(s,d);
    return 0;

}