#include<bits/stdc++.h>
using namespace std;
void solve(int o,int c,vector<string> &v, string op){  //solve 
    if(o==0 && c==0){
        v.push_back(op);
        return;
    }
    if(o!=0){
        string op1=op;
        op1.push_back('(');
        solve(o-1,c,v,op1);
    }
    if(c > o){
        string op1=op;
        op1.push_back(')');
        solve(o,c-1,v,op1);
    }
}
int main(){
int n;
cin>>n;
vector<string>v;
int o=n;
int c=n;
string op=" ";
solve(o,c,v,op);
for(auto i=v.begin();i!=v.end();i++){
    cout<<*i<<" ";
}
return 0;

}