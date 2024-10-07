#include<bits/stdc++.h>
using namespace std;
int solve(string str){
    int n=str.length();
    int t[n][n];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 ||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(str[i-1]==str[j-1] && i!=j){ 
                t[i][j]=t[i-1][j-1];
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][n];
}
int main(){
    string str;
    cin>> str;
    cout<<solve(str);
    return 0;
}