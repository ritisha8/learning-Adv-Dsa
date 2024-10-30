//we need to find the nnumber of way the expersiion will be true
// in order ot get the number of ways true we do need the number of ways false as well , only then we willl be able to calculate true ways
//when from the styart we onky find true ways of a string ,how inn thw end will be find the exact true ways , rue ways are calculated when 
//we have false ways as well right? otherwise how do you think is possible to calclate true ways
#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int solve(string s, int i, int j,bool isTrue){
    // base condiiton
    if(i>j){
        return false;  // when string is empty then simply no exp can be evaluated to true, 
    }
    if(i==j){
      if(isTrue){   // if required is true then we will check if s[i] is also true, is thta is , then return true otherwise flse
        return s[i]=='T';  
      }else{
        return s[i]=='F';
      }
    }
    int ans=0;
   string temp =to_string(i) +" "+ to_string(j) +" "+(isTrue? 'T':'F');
   if(mp.find(temp)!=mp.end()){
    return mp[temp];
   }
    // base condition done
    for(int k=i+1;k<=j-1;k=k+2){ // beacuse the starting   and end chrecter can never be symbols and we want k to break the exp on symbol only
      int lf=solve(s,i,k-1,false);
      int lt=solve(s,i,k-1,true);
      int rf=solve(s,k+1,j,false);
      int rt=solve(s,k+1,j,true);
      if(s[k]=='&'){  
        if(isTrue){  // if istrue is true means true wys need to be returned
           ans=ans+lt*rt;  // what happens in and only if both condiions are true then we move forward to execute statements in block otherwise we skip it right?
            // here also same , if we need true true happens in which cases in & , only when both will be true , so we compute lt*rt
        }else{  // if no. of false way are required
            ans=ans+lf*rf+lf*rt+lt*rf;  // then how many ways the exp can be false in & all other ways rather than both true right? 
            // thats what we do here , when both are false lf*rf , when one is true an another is false, lf*rt or lt*rf  so we added up all the combinations
        }
      }
      if(s[k]=='|'){
        if(isTrue){
          ans=ans+lf*rt+lt*rt+lt*rf;
        }else{
        ans=ans+lf*rf;
        } 
    }
    if(s[k]=='^'){
        if(isTrue){
            ans=ans+lt*rf+lf*rt;
        }else{
            ans=ans+lf*rf+lt*rt;
        }
    }
   }
   return mp[temp]=ans;  // finally return the number of ways
}
int main(){
    string s;
    cin>>s;
    int j=s.length()-1;
    mp.clear();
    cout<<solve(s,0,j,true);  // i j defined  // we have passed true because we want ot find thenumber of ways true will be evaluated with the exp
    return 0;
}