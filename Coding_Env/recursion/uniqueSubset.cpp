#include<bits/stdc++.h>
using namespace std;
void solve(string ip, string op,set<string>&s){
    
    if(ip.length()==0)
    {
        s.insert(op);   // instead of just cout<< op we simply insert each op string in set stl because set only recieve unique values and also in sorted order
        return ;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1,s);
    solve(ip,op2,s);
}
int main(){
    string ip;
    cin>>ip;
    string op=" ";
    set<string>s;  //here we just created a set and passed all the op strings in it
    solve(ip,op,s);
    for(auto it=s.begin();it!=s.end();it++){
        cout<<"["<<*it<<"]"<<" ";
    }
    return 0;
    
}