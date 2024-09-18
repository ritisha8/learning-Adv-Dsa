// whenever we need to check previous charecters there might be possibility that stack is being used here
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#include<bits/stdc++.h>
using namespace std;
bool solve(string s){
    stack<char>st;
    for(auto i=s.begin();i!=s.end();i++){
        if(st.empty()){
            st.push(*i);
        }else if(st.top()=='(' && *i==')' || st.top()=='{' && *i=='}' ||st.top()=='[' && *i==']'){
            st.pop();
        }
        else{
            st.push(*i);
        }
    }
    if(st.empty()){
        return true;
    }else{
        return false;
    }
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}