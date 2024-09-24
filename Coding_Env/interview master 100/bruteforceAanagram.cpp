#include<bits/stdc++.h>
using namespace std;
bool solve(string s, string t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}
int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    cout<<solve(s,t);
    return 0;
}