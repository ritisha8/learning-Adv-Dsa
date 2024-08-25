#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op){
    if(ip.length()==0){   // by recursion treee we get to know that we get the ans when ip beomes zero
        cout<<"["<<op<<"]"<<endl;  // so we print it 
        return;
    }
    string op1=op;  // we frist store the same output that we have in  empty variabnles op1 and op2
    string op2=op;  
    op1.push_back(' ');  // then as we take the first decision oftaking the string with spacees so we push space in op1
    op1.push_back(ip[0]);  //and then we push whtever is at idex 0 of ip
    op2.push_back(ip[0]);  // in output we make a decsion to simply take string without space so we simply push without space
    ip.erase(ip.begin()+0);  // and because fpor ip[0] the decsion has beeen taken sow e remove it and then 
    solve(ip,op1); // make a recursive call to solev function passing the reduced input and op1 where we deceided to take ip with space
    solve(ip,op2);  // thenwe make a recurive call to fucntion passing the reduced input and op2 where we deceided to take ip withoutwhere we deceided to take ip with space space

}
int main(){
string ip;
cin>>ip;
string op=" ";
// we will perform he the first cae in main because in frist case we dont have a choice we have only onw option of taking  the first letter wthout space 
op.push_back(ip[0]);
ip.erase(ip.begin()+0);
solve(ip,op);
return 0;
}
