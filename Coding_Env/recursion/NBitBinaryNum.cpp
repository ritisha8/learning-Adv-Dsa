#include<bits/stdc++.h>
using namespace std;
void solve(int n,string op,int ones,int zeros){
    if(n==0){
        cout<<op<<" ";
        return;
    }
    //we observe from thhe tree that 1's choiec we are always getting but the choice of zero is not alwayas aavailable , so when zxero choice is available 
    // it is available when 1s are greate than zeros because obviously when ones are equal and we add zero , poreficx will have more zeros which will make theprefix condition false
    // so for 1 one output is always goung to be there but second choice that is zero depends on the fact that ones should be grweater than zero
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