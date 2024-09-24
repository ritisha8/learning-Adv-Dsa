#include<bits/stdc++.h>
using namespace std;
bool solve(string s, string t){
    if(s.length()!=t.length()){
        return false;
    }
    map<char,int>mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
        mp[t[i]]--;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second!=0)
        {
            return false;
        }
    }
    return 0;
}
int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    cout<<solve(s,t);
    return 0;
}