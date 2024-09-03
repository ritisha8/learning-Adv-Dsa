// we have to create n digit binary no. whose prefix should have more no. of 1s than 0s or equal but 0s can never be greater
#include<bits/stdc++.h>
using namespace std;
void solve(int n,string op,int ones,int zeros){
    if(n==0){
        cout<<op<<" ";
        return ;
    }
    
    string op1=op;
    op1.push_back('1');
    solve(n-1,op1,ones+1,zeros);
    
    if(ones>zeros){
        string op2=op;
        op2.push_back('0');
        solve(n-1,op2,ones,zeros+1);
    }
}
int main(){
       int n;
    cin>>n;
    string op=" ";
    int ones=0;
    int zeros=0;
    solve(n,op,ones,zeros);
    return 0;

}