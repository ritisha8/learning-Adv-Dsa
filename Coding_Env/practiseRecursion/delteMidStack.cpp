#include<bits/stdc++.h>
using namespace std;
void solve(stack<int>&st,int k){
    if(k==1){  //smallest valid input
        st.pop();
        return;
    }
    int temp=st.top();
    st.pop();
    solve(st,k-1); // because when stack size decareses mid also should decrease, rec is making input smaller, in input we have two inputs right?, so both will be made small
    // if wwe dont decrease the mid the stack, then stack size only increase and k will point ot wrong midddle
    st.push(temp); // the llemnt we took out , we pushed it back , after mid is delted
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int k=(st.size()/2)+1;
    solve(st,k);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}