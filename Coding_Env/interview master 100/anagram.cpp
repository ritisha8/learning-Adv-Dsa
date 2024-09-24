
#include<bits/stdc++.h>
using namespace std;
bool solve(string s, string t){
    unordered_map<char,int>mp;
    unordered_map<char,int>mp2;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    for(int i=0;i<t.length();i++){
        mp2[t[i]]++;
    }
    if(mp==mp2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    cout<<solve(s,t);
    return 0;
}