// how will be get min no.of deletion and insertions in as string tomake it into another string 
// first we will see the common ellemtns in both strings 
//then we decide the llemtns beside the common ellemts in frist string are not needed in order to make intosecond string ,so we decide the deletion fromthere
//then we decide insertions by the elemtnsthat are ccommon how many ellemnts do we need toadd to them in order ot make them the ideal string needed.
// the ideal string length - commmon lemnts willl give us no. of insertions
// we are givenm two string one is the string we need to change , another is a string we want to change into, the required string

#include<bits/stdc++.h>
using namespace std;
int solve(string s, string d){
    int n=s.length();
    int m=d.length();
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                t[i][j]= 0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1]==d[j-1]){
                t[i][j]= t[i-1][j-1]+1;
            }else{
                t[i][j]=max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    int del=n-t[n][m];
    int ins=m-t[n][m];
    return ins+del;
}
int main(){
    string s;
    cin>>s;
    string d;
    cin>>d;
    cout<<solve(s,d);
    return 0;
}