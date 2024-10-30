// scrambled string is when we divide a string and make its subtree aand no subtree can have empty string , these are the two things we have to do with scrambled string 
//1. make binary tree 
// 2. no subtree can have empty string , so we can divide it from 1 , not from 0 because then one string will be full and another empty , we can divide it from 1 and further 
// till size-1; because at last also if we divide one subtree will have whole string and another empty which is not allowed

// here a string is a scrambled string when its nonleaf nodes's child nodes are swaped and then the string thta comes out after swappping and combining with the above subtree, will be a scrambled tree
// if a string's nonleaf nodes's child nodes are swapped zero or more times , then it is a scrambled string so , when a string is not even swapped at all, then also it is a scrambled string , if the string
// a is a scrambled string of string b then true is returned otherwise false
// so we have 2 cases here, if the leaf is swaped and if the leaf is not swapped

#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
bool solve(string a, string b){
    if(a.compare(b)==0)  {// when both strings are equal return true, this is the condition where the recursive call will stop it will not further divide the string, wherever they found it equal
       return true;
    }
    if(a.length()<=1){
        return false;  // when both string size was zero then it would have been returned true in upper statement, 
        //we know both strings are of same size so if anyone gets empty at any point then return false, because thta is not allowed and , we have done euqla here beacuse when 
        // when there will be size =1 ,if the string a and b were equal then it woukd have been true previously only if it is false then only it is comming down here so one 
        //thing is clear that they are not equal , so when we have one size string in bth which are not equal then obviously it is not scrambled string
    }
    string temp=a+" "+b;
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }
    int n=a.length();
    bool flag =false;
    for(int i=1;i<=n-1;i++){// it started from 1 becaus ewe want the string to divide from size 1 not from size 0  because that would not satisfy the condition
       if(solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i)) || 
       solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i)) ){
          flag=true;
          break;// because after thios we know if the string is crambked ornot we need npt go any further
       }
    }
    return mp[temp]=flag;

}
int main(){
    string a,b;
    cin>>a>>b;
    if(a.length()!=b.length()){
        return false;
    }else{
        cout<<solve(a,b);
    }
    
    return 0;
}