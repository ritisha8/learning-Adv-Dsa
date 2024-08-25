// wherever we have decsion and choices we perform recursion
#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op){  
    if(ip.length()==0){  // base condition tha we know from recursive tree that when ip becomes empty we get te ans
        cout<<"["<<op<<"]"<<" ";
        return;
    }  // what we did here is we made 2 descisions one 
    string op1=op;    // here we take an empty string to store op1
    string op2=op;    //here we take an empty string to store op2
    op1.push_back(tolower(ip[0]));  // in op1 first decsion we take lowercase of whtever charecter we have at index 0
    op2.push_back(toupper(ip[0]));  // in op2 second decision we take uppercase of whtever charecter we have at index 0 if is by defaukt upper toupper fucntion will have noeffect on it
    ip.erase(ip.begin()+0);  // thenwe erase the index 0for which the decsion has been taken from input 
    solve(ip,op1);  // now we pass the reduced input and op1 to rec call to perform all ofthis again until the input gets empty
    solve(ip,op2);  // after solve(ip,op1)  is done we call the same reudced ip and op2 and until the input gets empty;
}
int main(){
    string ip;
    cin>>ip;
    string op=" ";
    solve(ip,op);
    return 0;

}