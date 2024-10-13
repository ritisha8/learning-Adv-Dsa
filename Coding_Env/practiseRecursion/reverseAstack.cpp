#include<bits/stdc++.h>
using namespace std;
void insert(stack<int>&st,int temp){  // when we are reversing the stack and taking out the alst ellemnt from it , obviously wew ill be putting it at first now
    if(st.size()==0){
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
        return;
    }
    int temp=st.top();
    st.pop();
    solve(st);
    insert(st,temp);
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int n=st.size();
    solve(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}