// what is longest common superseuence? it is the concat of two strings , sowhat will be shprtest common supersequence, a supersequence which contains ellemnts of both strings but the common elemnts are taken only once
// so what are those common elements ? in wo strings ? we allready did . that is lcs. sowe simply find out lcs and retrun m+n -LCS

#include<bits/stdc++.h>
using namespace std;
int solve(string s,string d){
    int n=s.length();
    int m=d.length();
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 ||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1]==d[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }
            else{
                t[i][j]=max(t[i][j-1] ,t[i-1][j]);
            }
        }
    }
    return n+m - t[n][m];
}
int main(){
    string s;
    cin>>s;
    string d;
    cin>>d;
    cout<<solve(s,d);
    return 0;
}