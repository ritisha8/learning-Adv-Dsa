#include<bits./stdc++.h>
using namespace std;
void insert(stack<int>&st,int temp){
  if(st.size()==0 || st.top()<=temp){
    st.push(temp);
    return;
  }
  int val=st.top();
  st.pop();
  insert(st,temp);
  st.push(val);
}
void solve(stack<int>&st){
    if(st.size()==1){
        return ;
    }
    int temp=st.top();
    st.pop();
    solve(st);
    insert(st,temp);
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(90);
    st.push(30);
    st.push(45);
    st.push(15);
    int n=st.size();
    solve(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}