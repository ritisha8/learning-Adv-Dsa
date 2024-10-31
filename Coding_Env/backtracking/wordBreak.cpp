#include<bits/stdc++.h>
using namespace std;
void solve(string s,vector<string>&ans,int index,unordered_set<string>st,string &temp){
    //base case
    if(index==s.size()){
        temp.pop_back();  // to remove the trailing space at the end of string, before adding it to vector
        ans.push_back(temp);
        return;
    }
    string valid="";
    int tempSize=temp.size();  // this will store the size of orginal string and then
    // when we want to bakctrak our changes the string function erase will erase the string 
    //till it reaches its original size
    for(int i=index;i<s.size();i++){
     valid=valid+s[i];
     if(st.find(valid)!=st.end()){
        temp=temp+valid;
        temp.push_back(' ');
        solve(s,ans,i+1,st,temp);
        temp.erase(tempSize);
     }
    }
}
vector<string> solve(string s, vector<string>&dict){
    vector<string>ans;
    unordered_set<string>st(dict.begin(),dict.end());  // because lookups are efficient in set than vectors
    string temp="";
    solve(s,ans,0,st,temp);
    return ans;
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string>dict(n);
    for(int i=0;i<n;i++){
        cin>>dict[i];
    }
    vector<string>v=solve(s,dict);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}