#include<bits/stdc++.h>
using namespace std;
void insert(int temp, stack<int>&st){
    if(st.size()==0) {
        st.push(temp);
        return ;
    }
    int val=st.top();
    st.pop();
    insert(temp,st);
    st.push(val);
}
void rev(stack<int> &st){
    if(st.size()==1) return;
    int temp=st.top();
    st.pop();
    rev(st);
    insert(temp,st);
}
int main(){
    stack<int>st;
    st.push(50);
    st.push(40);
    st.push(30);
    st.push(20);
    st.push(10);
    rev(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}