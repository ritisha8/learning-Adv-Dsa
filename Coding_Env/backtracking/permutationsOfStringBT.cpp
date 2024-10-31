// why dow e neeed to do backtracking , think o three persons
// one wearing black clothes , another wearing red, and aother wearing white
// now what would bemore intuitive , for getting permutaions , brining new pwoplw at evry stage and dressign them amng those colours or 
// swapping the induvidals in place to make all the permuations.
// ofc swapping right? , thta can be done in balctracking , in bakctracking instead of making new vaibales eahc tiem in ecursive calls ,we swap the variables and make the changes in place 
//what is bakctrakcing = controlled recursion + pass by ref
// so we allready implmented controlled recursion in recrsion, here we will implement pass by reference
// now why dow e do pass by reference? because as we are maiing the change in the address itself then wheneverr another choice has to be made fr the same elvel , the va;lue ata ddress will not be same
//it will be changed, and in order to egt the proper answer what we want is the variable to remain same, so we revert the chnages we made before making a rcursive call to the function, so that before 
//thee is antoher choices to be made ,
//the string is in its orginal value

#include<bits/stdc++.h>
using namespace std;
void solve(string &s,int start,vector<string>&v){
    //bc
    if(start==s.size()-1){  // when start pointer starts pointer to the last node, then we get  our ans instring according to backtraking tree
        v.push_back(s);  // before we have input putut here we have the string only becase we are making the hcanges in place 
        return;
    }
    unordered_set<char>st;  // tp control recrusion
    for(int i=start;i<s.length();i++){  // we aremoving froms atrt to end end ofateing  because we can make chnages from satrt to end ony , any string befre start has been fixed and desion for thta has been taken
        if(st.find(s[i])==st.end()){  //we are starting from start because the choices we further need tomake will be from start to end , the choices of swap
            st.insert(s[i]);
            swap(s[start],s[i]);   // acording to BT tree
            solve(s,start+1,v);
            swap(s[start],s[i]);  // backtraking step
        }
    }
}
vector<string> permute(string s){
    vector<string>v;
    solve(s,0,v); // in recursive we took ip op , here we need to take the start pointer
    return v;
    
}
int main(){
  string s;
  cin>>s;
  vector<string>v=permute(s);
  for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
  return 0;
}
