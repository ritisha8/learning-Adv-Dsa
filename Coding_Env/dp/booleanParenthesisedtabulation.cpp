#include<bits/stdc++.h>
using namespace std;
int t[2][201][201];
int solve(string s,int i,int j,bool isTrue){
    if(i>j) return t[isTrue][i][j]=0; 
    if(i==j){
        if(isTrue){
            return t[isTrue][i][j]=s[i]=='T';
        }else{
            return t[isTrue][i][j]=s[i]=='F';
        }
    }
    if(t[isTrue][i][j]!=-1){
        return t[isTrue][i][j];
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){
        int lt,rt,rf,lf;
        lt=solve(s,i,k-1,true);
        lf=solve(s,i,k-1,false);
        rt=solve(s,k+1,j,true);
        rf=solve(s,k+1,j,false);
        if(s[k]=='&'){
            if(isTrue){
             ans=ans+lt*rt;
            }else{
            ans=ans+lf*rf+lt*rf+rt*lf;
           }
        }
         
        if(s[k]=='|'){
            if(isTrue){
                ans=ans+lf*rt+lt*rf+lt*rt;
            }else{
                ans=ans+lf*rf;
            }
        }
        if(s[k]=='^'){
            if(isTrue){
                ans=ans+lf*rt+rf*lt;
            }else{
                ans=ans+lf*rf+rt*lt;
            }
        }
    }
    return t[isTrue][i][j]=ans;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    memset(t,-1,sizeof(t));
    cout<<solve(s,0,n-1,true);  // i j defied
    return 0;
}