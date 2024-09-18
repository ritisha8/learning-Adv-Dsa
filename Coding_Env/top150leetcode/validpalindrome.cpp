#include<bits/stdc++.h>
using namespace std;
bool solve(string s){
    int start=0;
    int end=s.length()-1;
    while(start<=end){
      if(!isalnum(s[start])){
        start++;
        continue;
      }
      if(!isalnum(s[end])){
        end--;
        continue;
      }
      if(tolower(s[start])!=tolower(s[end])){
        return false;
     }
     else{
        start++;
        end--;
    }
    }
    return true;
    
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}