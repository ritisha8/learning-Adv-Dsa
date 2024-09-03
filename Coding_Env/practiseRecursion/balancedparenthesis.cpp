#include<bits/stdc++.h>
using namespace std;
void solve(int o,int c,string op,vector<string>&v){
    if(o==0 && c==0){
        v.push_back(op);
        return;
    }
     if(o!=0){  // open can be used everytime until it is empty
        string op1=op;
        op1.push_back('(');
        solve(o-1,c,op1,v);   
     }
     if(c>o){   // c can be used onl when it is more than o , so that it can balance it out
       string op2=op;
       op2.push_back(')');
       solve(o,c-1,op2,v);
     }
}
int main(){
    int n;
    cin>>n;
    string op=" ";
    int o=n;
    int c=n;
    vector<string>v;
    solve(o,c,op,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}