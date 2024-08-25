//this letter case permutation is a problem whrer we are gievn an alphanumeric string in which we have to make change in letter case and didgitd will remain same
//we can perform this in permuation with case change way as well because tolower and  toupper functions have no effect on digits so it will give us output but it will contain some duplicate values
// as for the digitwe need not to take two vase for desion we need only one case that is directly just taking digit as it is and in permutation case change we asuume that we rae given only alphabetical string so we make 2 case for each alphabet
// so when we add digit in input as we have not added any additional condition for diogit it will perform two cases for digit as well and then we  will have duplicaste values
#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op,vector<string>&v){
    if(ip.length()==0){
        v.push_back(op);
        return;
    }
   
    if(isalpha(ip[0])){  // if ip[0] is an alphabet then we have two choices to make one either it is going to be ,lower case or it is going to be upper case
        string op1=op;  // string to store 1st decsion
        string op2=op;  // string to store second desicion
        // taking first decision of lowercase letter
        op1.push_back(tolower(ip[0]));
        // taking second decsiopn of taking letter as uppercase
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin()+0); // now decrerasing input as decsion has been taken for ip[0]
        solve(ip,op1,v);
        solve(ip,op2,v);
    }else{
      // if it is not alphabet we have only one decsion to make  that is take the alphabet as it is because there is no case change in alpahbets right?
    string op1=op;// because here we have only one choice so only  one decision 
    op1.push_back(ip[0]); //then we push the digit directly in op1
    ip.erase(ip.begin()+0);  // and thenwe have taken the decsion fro this inp[0],we erase it
    solve(ip,op1,v);  // now we make arecusrive call to reduced inp and op1 ;
    }
   
}
int main(){
    string ip;
    cin>>ip;
    string op=" ";
    vector<string>v;
    solve(ip,op,v);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<"["<<*it<<"]"<<" ";
    }
    return 0;
}