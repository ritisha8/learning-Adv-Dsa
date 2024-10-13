#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int solve(string s,int i,int j,bool isTrue){
    if(i>j) return 0;  //when i>j menas exp size is 0 , when there is no exp,how can we evaluate it to true,so zero 
    if(i==j){
        if(isTrue){
            return s[i]=='T';  // is true is true and s[i] == 'T' then true will be returned or 1, 
        }else{
            return s[i]=='F'; //otherwise false will be returned or 0
        }
    }
    //base condition done
    string temp=to_string(i)+" "+to_string(j)+" "+(isTrue? 'T':'F');
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }
    // k loop scheme
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){ //because when i and j will always be staring and ending ellemnts and k=k+@ becausewe want k to divide the subprobelms 
    //onsymbols only not on i or j because thta will not make any sense
    int lf=solve(s,i,k-1,false);  // we have to calculat both false asw ell as true ways of left and right in order ot calculate the kth symbol, 
    int lt=solve(s,i,k-1,true);  //which divides the two subproblems
    int rf=solve(s,k+1,j,false);  
    int rt=solve(s,k+1,j,true);
    //now we will check the value of k and accordinly calculate
    if(s[k]=='&'){
        if(isTrue){   // if we want to find true ways
           ans=ans+lt*rt;  // in how many ways '&' is true , only one way right? when left is true and right is true
        }else{
            ans=ans+lf*rt+lt*rf+lf*rf;  // all oher ways its false, so in false ways this is how its computed
        }
    }
    if(s[k]=='|'){  // even one of the both is true the exp can be true
        if(isTrue){
            ans=ans+lt*rf+lf*rt+lt*rt;  // so the true ways are these
        }else{
            ans=ans+lf*rf;
        }
    }
    if(s[k]=='^'){
        if(isTrue){
            ans=ans+lf*rt+lt*rf;  // when diff variables , then true ways
        }
        else{
            ans=ans+lt*rt+lf*rf; // when same , then false ways
        }
    }
    }
    return mp[temp]=ans;
}
int main(){
    string s;
    cin>>s;
    int j=s.length()-1;
    mp.clear();
    cout<<solve(s,0,j,true); // i j defined
    return 0;
}