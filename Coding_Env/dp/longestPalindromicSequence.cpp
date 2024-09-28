//we are given a single string here and this question is definately a lcs variation , how do we know that ,we match 3 things of eahc question with lcs if even 2 of them we consider the problem as a variation
// what re 3 things 
//1 input : in lcs input we have 2 strings , here we have 1 only  0.5/3
//2 output: in lcs output we want an integer, here also we want an integer 1/3
//3 ques : LOngest common subsequence , longest palindromic sequence 0.5/3
// in total we get 2/3;
// here lcs variation ,we know lcs is going to be there. but for lcs we need two strings . here we have only one . hiw can we get another string ?
// as this is a palindromic question ,lets try the reverse of string to be second string
// then what will be longest palindromic sequence in both of them?
//lets take a string : abcdbag  , rev string would be : gabdcba
// first lets find the palindromic sequence of abcdbag : abcba, bcb, aa, aba, abba
//now lets see how do we get the longest palindromic seuqence , when we find lcs of rev string and general string we get the longest palindromic string if you observe closely

#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    string d=s;
    reverse(d.begin(),d.end());
    int n=s.length();
    int m=d.length();
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
            if(s[i-1]==d[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][m];
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}