#include<bits/stdc++.h>
using namespace std;
void solve(int o,int c,vector<string> &v, string op){  //solve 
    if(o==0 && c==0){
        v.push_back(op);
        return;
    }
    if(o!=0){   //until opening brackets are not finished we can use them,because there is no concern 
    //regarding opening brackets they willnot craete imbaalnce if they are used first they can b
    // balced by closingbrackets after it, and when opening brackets are finished, then closig are alays left
    // to ill and balance it,but thta might not be the case in closign brackets
        string op1=op;
        op1.push_back('(');
        solve(o-1,c,v,op1);
    }
    if(c > o){   // because if closing brackets are equal to openingor greater than opening, 
    //it will make opening brackets to be left more,for whomclosing braclets willnot be
    // enouh to make it balanced, so op2 willonly be generated when closing brackets are more than
    // opening so that we can make it balanced, if they are equal then it is al;ready balanced , 
    //and if we add op2 with one closing bracket, it leads to imbalance, because theopening now 
    //closign brackets is reeduced by one and ipening brackets remain same,and now opening brcakts 
    //are more than closing which means there are not enough closing brackets to balkance opening ones 
    //hence a balanced op is nott posssible
        string op2=op;
        op2.push_back(')');
        solve(o,c-1,v,op2);
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