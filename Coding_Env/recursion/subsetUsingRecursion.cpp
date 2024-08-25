//subset,power set and subsequence has little to no variations in them 
#include<bits/stdc++.h>
using namespace std;
//this is input /output approachto a recursive problem
// before approaching to this prob we make a recurive tree which makes it quite easy
void subset(string ip,string op){  
    if(ip.length()==0){   // in recursive tree when input becomes empty , we get all the subets possible so we initial;izeed input as empty in base case
        cout<<"["<<op<<"]"<<" ";  // when we reach inpuit empty we print op there , which is each subset
        return;  // then we return;
    }
    string op1=op;  // then we take a string and initialize the string with with the outp because if inut is not empty
    string op2=op;  // then we take a
    op2.push_back(ip[0]);  // we push ip[0] in op2 because op1 remains same  as in first desicion we dont take ip[0] and in second decision we take input 0
    ip.erase(ip.begin()+0);  // erasing 0th ele from inp because we took the decision for it
    subset(ip,op1);  //then we do recursive call on op1
    subset(ip,op2);  // then we make a recursive call to inp and op2
    return;  // then we return to mnain function

}
int main(){
    string ip;  // we take a string inp0ut
    cin>>ip;
    string op=" ";  // we initializwe output as eempty
    subset(ip,op);  //and then we call this function subset whcih returns us  all subsets of iput
    return 0;
}